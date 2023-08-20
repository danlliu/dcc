
#include "ir.h"

#include "arm64.h"
#include "compiler_context.h"
#include "label_manager.h"
#include "macros.h"
#include "register_allocator.h"

using namespace dlang;

unsigned IRNode::NEXT_ID = 0;

#define RUN_AND_SET_LIVENESS \
  do { \
    if (livenessPass) return; \
    livenessPass = true; \
  } while (0)

#define UPDATE_LIVENESS            \
  do {                             \
    ra.addLivenessState(liveness); \
  } while (0)

void IRStartNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  UPDATE_LIVENESS;
}

void IRBlockStartNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  UPDATE_LIVENESS;
}

void IRBlockEndNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  UPDATE_LIVENESS;
}

void IRLoopEndNode::makeLivenessPass(VariableScopeManager &vsm, RegisterAllocator &ra) {
  RUN_AND_SET_LIVENESS;
  liveness.resize(vsm.getNumVariables());
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness |= next->getLiveness();
  }
  if (auto l = loop.lock()) {
    l->makeLivenessPass(vsm, ra);
    liveness |= l->getLiveness();
  }
  UPDATE_LIVENESS;
}

void IRMergeNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness = next->getLiveness();
  } else {
    liveness.resize(vsm.getNumVariables());
  }
  UPDATE_LIVENESS;
}

void IRConditionalNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
  liveness.resize(vsm.getNumVariables());
  if (trueIR) {
    trueIR->makeLivenessPass(vsm, ra);
    liveness |= trueIR->getLiveness();
  } else {
    UNREACHABLE("Conditional must have a true path");
  }
  if (falseIR) {
    falseIR->makeLivenessPass(vsm, ra);
    liveness |= falseIR->getLiveness();
  } else {
    // Here, we know that trueIR connects via BlockEnd to next (the MergeNode),
    // so we don't have to worry about calling makeLivenessPass
    liveness |= next->getLiveness();
  }
  // no need to do next since it's covered by at least one path above
  liveness.setLive(condition.id);
  UPDATE_LIVENESS;
}

void IRLoopNode::makeLivenessPass(VariableScopeManager &vsm, RegisterAllocator &ra) {
  RUN_AND_SET_LIVENESS;
  // IRBlockEndNode at end of loop will look at this liveness
  liveness.resize(vsm.getNumVariables());
  liveness.setLive(conditionVR.id);
  if (body) {
    body->makeLivenessPass(vsm, ra);
    liveness |= body->getLiveness();
  }
  if (next) {
    next->makeLivenessPass(vsm, ra);
    liveness |= next->getLiveness();
  }
  UPDATE_LIVENESS;
}

void IRAssignNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
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

void IROperationNode::makeLivenessPass(VariableScopeManager& vsm, RegisterAllocator& ra) {
  RUN_AND_SET_LIVENESS;
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
  RUN_AND_SET_LIVENESS;
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

void IRStartNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (next) next->toAssembly(ra, o);
}

void IRBlockStartNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (next) next->toAssembly(ra, o);
}

void IRBlockEndNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  // Stop here
}

void IRLoopEndNode::toAssembly(const RegisterAllocator &ra, std::ostream &o) {
  // Stop here, we handle all the loop logic in LoopNode.
}

void IRMergeNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (next) next->toAssembly(ra, o);
}

void IRConditionalNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (falseIR) {
    // Generate two labels: one for false, one for end
    auto falseLabel = LabelManager::nextLabel();
    auto endLabel = LabelManager::nextLabel();
    // Conditional
    o << ARM64BranchIfNonZero { condition.toReg(ra), { falseLabel } };
    // First if
    trueIR->toAssembly(ra, o);
    o << ARM64UnconditionalJump { endLabel };
    o << ARM64Label { falseLabel } << "\n";
    // Then else
    falseIR->toAssembly(ra, o);
    o << ARM64Label { endLabel } << "\n";
    next->toAssembly(ra, o);
  } else {
    auto endLabel = LabelManager::nextLabel();
    // Conditional
    o << ARM64BranchIfNonZero { condition.toReg(ra), { endLabel } };
    // First if
    trueIR->toAssembly(ra, o);
    o << ARM64Label { endLabel } << "\n";
    next->toAssembly(ra, o);
  }
}

void IRLoopNode::toAssembly(const RegisterAllocator &ra, std::ostream &o) {
  // Generate two labels: one for start, one for end
  auto startLabel = LabelManager::nextLabel();
  auto endLabel = LabelManager::nextLabel();
  o << ARM64Label { startLabel } << "\n";
  // Condition
  conditionIR->toAssembly(ra, o);
  o << ARM64BranchIfZero { conditionVR.toReg(ra), { endLabel } };
  // Body
  body->toAssembly(ra, o);
  // End body
  o << ARM64UnconditionalJump { { startLabel } };
  // End label
  o << ARM64Label { endLabel } << "\n";
  next->toAssembly(ra, o);
}

void IRAssignNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (next && !next->getLiveness().isLive(lhs.id)) {
    // dead on arrival
    if (next) next->toAssembly(ra, o);
    return;
  }

  o << ARM64Mov { lhs.toReg(ra), rhs.toReg(ra) };
  if (next) next->toAssembly(ra, o);
}

void IROperationNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  if (next && !next->getLiveness().isLive(dest.id)) {
    // dead on arrival
    if (next) next->toAssembly(ra, o);
    return;
  }

  o << ARM64Operation { dest.toReg(ra), lhs.toReg(ra), op, rhs.toReg(ra) };
  if (next) next->toAssembly(ra, o);
}

void IRReturnNode::toAssembly(RegisterAllocator const& ra, std::ostream& o) {
  o << ARM64Mov { ARM64ReturnRegister, val.toReg(ra) };
  o << ARM64Return {};
}