
#include "ir.h"
#include "compiler_context.h"
#include "register_allocator.h"

using namespace dlang;

unsigned IRNode::NEXT_ID = 0;

std::ostream& operator<<(std::ostream& os, Operator op) {
  switch (op) {
  case PLUS:
    return os << "+";
  case MINUS:
    return os << "-";
  case MULTIPLY:
    return os << "*";
  case DIVIDE:
    return os << "/";
  case AND:
    return os << "&";
  case OR:
    return os << "|";
  case XOR:
    return os << "^";
  case LSHIFT:
    return os << "<<";
  case RSHIFT:
    return os << ">>";
  }
}

#define UPDATE_LIVENESS do { \
  livenessPass = true; \
  ra.addLivenessState(liveness); \
} while (0)

void IRStartNode::makeLivenessPass(VariableScopeManager &vsm, RegisterAllocator& ra) {
  if (livenessPass) return;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  UPDATE_LIVENESS;
}

void IRAssignNode::makeLivenessPass(VariableScopeManager &vsm, RegisterAllocator& ra) {
  if (livenessPass) return;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  // if the result isn't even live, dead on arrival. no need to compute
  if (liveness.isLive(lhs.id)) {
    liveness.setNotLive(lhs.id);
    liveness.setLive(rhs.id);
  }
  UPDATE_LIVENESS;
}

void IROperationNode::makeLivenessPass(VariableScopeManager &vsm, RegisterAllocator& ra) {
  if (livenessPass) return;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  if (liveness.isLive(dest.id)) {
    liveness.setNotLive(dest.id);
    liveness.setLive(lhs.id);
    liveness.setLive(rhs.id);
  }
  UPDATE_LIVENESS;
}

void IRReturnNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  if (livenessPass) return;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  liveness.setLive(val.id);
  UPDATE_LIVENESS;
}

// To assembly

void IRStartNode::toAssembly(const RegisterAllocator &ra, std::ostream &o) {
  if (next)
    next->toAssembly(ra, o);
}

void IRAssignNode::toAssembly(const RegisterAllocator &ra, std::ostream &o) {
  if (next && !next->getLiveness().isLive(lhs.id)) {
    // dead on arrival
    if (next) next->toAssembly(ra, o);
    return;
  }

  o << ARM64Mov{ lhs.toReg(ra), rhs.toReg(ra) };
  if (next)
    next->toAssembly(ra, o);
}

void IROperationNode::toAssembly(const RegisterAllocator &ra, std::ostream &o) {
  if (next && !next->getLiveness().isLive(dest.id)) {
    // dead on arrival
    if (next) next->toAssembly(ra, o);
    return;
  }

  o << ARM64Operation{ dest.toReg(ra), lhs.toReg(ra), op, rhs.toReg(ra) };
  if (next)
    next->toAssembly(ra, o);
}

void IRReturnNode::toAssembly(const RegisterAllocator& ra, std::ostream& o) {
  o << ARM64Mov{ ARM64ReturnRegister, val.toReg(ra) };
  o << ARM64Return {};
}