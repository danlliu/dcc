
#ifndef _DCC_IR_H
#define _DCC_IR_H

#include <iostream>
#include <memory>
#include <vector>

#include "compiler_context.h"
#include "macros.h"
#include "register_allocator.h"
#include "tokens.h"

namespace dlang {

class IRNode {
 public:
  IRNode() : id(NEXT_ID++) {}
  std::shared_ptr<IRNode> next;
  unsigned id;
  static unsigned NEXT_ID;

  virtual ~IRNode() {}

  virtual void dump(std::ostream& o) {
    if (dumped)
      o << "{" << id << "}";
    else {
      dumped = true;
      dump_impl(o);
    }
  }
  virtual void toAssembly(const RegisterAllocator& ra, std::ostream& o) = 0;
  virtual void makeLivenessPass(VariableScopeManager&, RegisterAllocator& ra) = 0;
  virtual LivenessManager getLiveness() { return liveness; }

 protected:
  virtual void dump_impl(std::ostream& o) = 0;
  inline void dumpLiveness(std::ostream& o) {
    o << liveness;
  }

  // bitset representing liveness of virtual registers BEFORE this instruction
  LivenessManager liveness;
  bool dumped = false;
  bool livenessPass = false;
};

class IRStartNode : public IRNode {
 public:
  IRStartNode() : IRNode() {}

  virtual void toAssembly(const RegisterAllocator& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;
 private:
  virtual void dump_impl(std::ostream& o) override {
    o << "{ START " << id << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IRAssignNode : public IRNode {
 public:
  IRAssignNode(VirtualRegister l, VirtualRegister r)
    : IRNode(), lhs(l), rhs(r) {}
  VirtualRegister lhs;
  VirtualRegister rhs;

  virtual void toAssembly(const RegisterAllocator& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;
 private:
  virtual void dump_impl(std::ostream& o) override {
    if (livenessPass) {
      o << "{ Assign < ";
      dumpLiveness(o);
      o << " > ";
    }
    else
      o << "{ Assign ";
    o << lhs << ", " << rhs << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

}

std::ostream& operator<<(std::ostream& os, dlang::Operator op);

namespace dlang {

class IROperationNode : public IRNode {
 public:
  IROperationNode(VirtualRegister dest, VirtualRegister lhs, Operator op, VirtualRegister rhs)
    : dest(dest), lhs(lhs), op(op), rhs(rhs) {}
  VirtualRegister dest;
  VirtualRegister lhs;
  Operator op;
  VirtualRegister rhs;

  virtual void toAssembly(const RegisterAllocator& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;
 private:
  virtual void dump_impl(std::ostream& o) override {
    if (livenessPass) {
      o << "{ Operation < ";
      dumpLiveness(o);
      o << " > ";
    }
    else
      o << "{ Operation ";
    o << dest << " = " << lhs << " " << op << " " << rhs << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IRReturnNode : public IRNode {
 public:
  IRReturnNode(VirtualRegister vr)
    : IRNode(), val(vr) {}
  VirtualRegister val;

  virtual void toAssembly(const RegisterAllocator& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;
 private:
  virtual void dump_impl(std::ostream& o) override {
    if (livenessPass) {
      o << "{ Return < ";
      dumpLiveness(o);
      o << " > ";
    }
    else
      o << "{ Return ";
    o << val << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

}


#endif
