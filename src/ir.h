
#ifndef _DCC_IR_H
#define _DCC_IR_H

#include <iostream>
#include <memory>
#include <vector>

#include "arm64.h"
#include "compiler_context.h"
#include "macros.h"
#include "register_allocator.h"
#include "tokens.h"

#define DUMP_WITH_LIVENESS(X, os) \
  do {                            \
    if (livenessPass) {           \
      os << "{ " #X " < ";        \
      dumpLiveness(os);           \
      os << " > ";                \
    } else                        \
      os << "{ " #X " ";          \
    os << "[" << id << "] ";     \
  } while (0)

namespace dlang {

class IRNode {
  public:
  IRNode()
      : id(NEXT_ID++) {}
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
  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) = 0;
  virtual void makeLivenessPass(VariableScopeManager&, RegisterAllocator& ra) = 0;
  virtual LivenessManager getLiveness() { return liveness; }

  protected:
  virtual void dump_impl(std::ostream& o) = 0;
  inline void dumpLiveness(std::ostream& o) { o << liveness; }

  // bitset representing liveness of virtual registers BEFORE this instruction
  LivenessManager liveness;
  bool dumped = false;
  bool livenessPass = false;
};

class IRStartNode : public IRNode {
  public:
  IRStartNode()
      : IRNode() {}

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    o << "{ START [" << id << "] }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IRBlockStartNode : public IRNode {
  public:
  IRBlockStartNode()
      : IRNode() {}

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(BlockStart, o);
    o << id << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IRBlockEndNode : public IRNode {
  public:
  IRBlockEndNode()
      : IRNode() {}

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(BlockEnd, o);
    o << id << " }";
  }
};

class IRMergeNode : public IRNode {
  public:
  IRMergeNode()
      : IRNode() {}

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(Merge, o);
    o << id << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IRConditionalNode : public IRNode {
  public:
  IRConditionalNode(VirtualRegister condition)
      : IRNode()
      , condition(condition) {}

  VirtualRegister condition;
  std::shared_ptr<IRNode> trueIR;
  std::shared_ptr<IRNode> falseIR;

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(Conditional, o);
    o << id << " }";
    if (trueIR) {
      o << " -IF-> ";
      trueIR->dump(o);
    }
    if (falseIR) {
      o << " -ELSE-> ";
      falseIR->dump(o);
    }
    if (next) {
      o << " -ENDIF-> ";
      next->dump(o);
    }
  }
};

class IRAssignNode : public IRNode {
  public:
  IRAssignNode(VirtualRegister l, VirtualRegister r)
      : IRNode()
      , lhs(l)
      , rhs(r) {}
  VirtualRegister lhs;
  VirtualRegister rhs;

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(Assign, o);
    o << lhs << ", " << rhs << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

class IROperationNode : public IRNode {
  public:
  IROperationNode(VirtualRegister dest, VirtualRegister lhs, Operator op, VirtualRegister rhs)
      : dest(dest)
      , lhs(lhs)
      , op(op)
      , rhs(rhs) {}
  VirtualRegister dest;
  VirtualRegister lhs;
  Operator op;
  VirtualRegister rhs;

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(Operation, o);
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
      : IRNode()
      , val(vr) {}
  VirtualRegister val;

  virtual void toAssembly(RegisterAllocator const& ra, std::ostream& o) override;
  virtual void makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) override;

  private:
  virtual void dump_impl(std::ostream& o) override {
    DUMP_WITH_LIVENESS(Return, o);
    o << val << " }";
    if (next) {
      o << " -> ";
      next->dump(o);
    }
  }
};

}   // namespace dlang


#endif
