
#include "compiler.h"

#include <memory>

#include "arm64.h"
#include "ast.h"
#include "compiler_context.h"
#include "ir.h"
#include "macros.h"
#include "register_allocator.h"

using namespace dlang;

// IR Conversion

#define NO_IR_NODE prev
#define NO_VR \
  {}
#define NO_IR(t)                                                                                              \
  IRResult dlang::AST_NODE_NAME_FOR_TYPE(t)::convertToIR(VariableScopeManager&, std::weak_ptr<IRNode> prev) { \
    return {                                                                                                  \
      prev, {0, 0}                                                                                          \
    };                                                                                                        \
  }
#define TO_IR(t) \
  IRResult dlang::AST_NODE_NAME_FOR_TYPE(t)::convertToIR(VariableScopeManager& vsm, std::weak_ptr<IRNode> prev)

// Terminals

NO_IR(assign);
NO_IR(delim);
NO_IR(return);
NO_IR(if);
NO_IR(else);
NO_IR(while);
NO_IR(lbrace);
NO_IR(rbrace);
NO_IR(plus);
NO_IR(minus);
NO_IR(multiply);
NO_IR(divide);
NO_IR(bitand);
NO_IR(bitor);
NO_IR(bitxor);
NO_IR(lshift);
NO_IR(rshift);
NO_IR(lparen);
NO_IR(rparen);

TO_IR(num) {
  int value = std::stoi(this->m_token.value);
  return {
    NO_IR_NODE, {0, value}
  };
}

TO_IR(ident) {
  return { NO_IR_NODE, { vsm.lookup(this->m_token.value) } };
}

// Non-terminals

TO_IR(Expr) {
  if (size(m_children) == 1) return m_children[0]->convertToIR(vsm, prev);
  if (size(m_children) == 2) {
    // - num
    IRResult num = m_children[1]->convertToIR(vsm, prev);
    num.result.constValue *= -1;
    return num;
  }
  if (size(m_children) != 3) UNREACHABLE("Expr with incorrect number of children encountered during IR generation");
  if (m_children[0]->type() == ASTNodeType_lparen) {
    // ( Expr )
    auto expr = m_children[1]->convertToIR(vsm, prev);
    return expr;
  } else {
    // Expr (op) Expr
    auto [lhsIR, lhsVR] = m_children[0]->convertToIR(vsm, prev);
    auto [rhsIR, rhsVR] = m_children[2]->convertToIR(vsm, lhsIR);
    auto op = toOperatorStruct(m_children[1]->token());
    // constant folding
    if (lhsVR.isConst() && rhsVR.isConst()) {
      prev.lock()->next.reset();
      return {
        NO_IR_NODE, {0, evaluateOperator(lhsVR.constValue, op, rhsVR.constValue)}
      };
    }
    // at least one side a variable
    auto dest = vsm.addTemp();
    auto assign = std::make_shared<IROperationNode>(dest, lhsVR, op, rhsVR);
    rhsIR.lock()->next = assign;
    return { assign, dest };
  }
}

TO_IR(Block) {
  if (size(m_children) == 1)
    return m_children[0]->convertToIR(vsm, prev);
  else if (size(m_children) == 2) {
    IRResult block_l = m_children[0]->convertToIR(vsm, prev);
    IRResult statement = m_children[1]->convertToIR(vsm, block_l.ir_last);
    return statement;
  } else
    UNREACHABLE("Block with no children or more than 2 children encountered during IR generation");
}

TO_IR(Statement) {
  if (size(m_children) == 1)
    return m_children[0]->convertToIR(vsm, prev);
  else
    UNREACHABLE("Statement with no children or more than 1 child encountered during IR generation");
}

TO_IR(AssignStatement) {
  if (size(m_children) != 4) {
    UNREACHABLE("Invalid assignment statement encountered during IR generation: invalid number of children nodes");
  }
  if (m_children[0]->type() != dlang::ASTNodeType_ident)
    UNREACHABLE("Invalid assignment statement encountered during IR generation: invalid LHS");
  auto def = dynamic_cast<ASTNode_ident*>(m_children[0].get())->token().value;
  auto [useIR, useVR] = m_children[2]->convertToIR(vsm, prev);
  auto defVR = vsm.add(def);
  auto assignIRNode = std::make_shared<IRAssignNode>(defVR, useVR);
  useIR.lock()->next = assignIRNode;
  return { assignIRNode, NO_VR };
}

TO_IR(ReturnStatement) {
  auto [resIR, resVR] = m_children[1]->convertToIR(vsm, prev);
  auto returnIRNode = std::make_shared<IRReturnNode>(resVR);
  resIR.lock()->next = returnIRNode;
  return { returnIRNode, NO_VR };
}

TO_IR(IfStatement) {
  // 0 = if
  // 1 = lparen
  // 2 = Expr
  auto [conditionIR, conditionVR] = m_children[2]->convertToIR(vsm, prev);
  // 3 = rparen
  // Create the IRConditionalNode
  auto conditionalNode = std::make_shared<IRConditionalNode>(conditionVR);
  conditionIR.lock()->next = conditionalNode;
  // 4 = lbrace
  // 5 = Block
  auto ifCondition = std::make_shared<IRBlockStartNode>();
  conditionalNode->trueIR = ifCondition;
  auto [trueIR, trueVR] = m_children[5]->convertToIR(vsm, ifCondition);
  auto endIf = std::make_shared<IRBlockEndNode>();
  trueIR.lock()->next = endIf;

  // rbrace
  auto mergeNode = std::make_shared<IRMergeNode>();
  endIf->next = mergeNode;
  conditionalNode->next = mergeNode;
  return { mergeNode, NO_VR };
}

TO_IR(IfElseStatement) {
  // 0 = if
  // 1 = lparen
  // 2 = Expr
  auto [conditionIR, conditionVR] = m_children[2]->convertToIR(vsm, prev);
  // 3 = rparen
  // Create the IRConditionalNode
  auto conditionalNode = std::make_shared<IRConditionalNode>(conditionVR);
  conditionIR.lock()->next = conditionalNode;
  // 4 = lbrace
  // 5 = Block
  auto ifCondition = std::make_shared<IRBlockStartNode>();
  conditionalNode->trueIR = ifCondition;
  auto [trueIR, trueVR] = m_children[5]->convertToIR(vsm, ifCondition);
  auto endIf = std::make_shared<IRBlockEndNode>();
  trueIR.lock()->next = endIf;
  // 6 = rbrace
  // 7 = else
  // 8 = lbrace
  // 9 = Block
  auto elseCondition = std::make_shared<IRBlockStartNode>();
  conditionalNode->falseIR = elseCondition;
  auto [falseIR, falseVR] = m_children[9]->convertToIR(vsm, elseCondition);
  auto endElse = std::make_shared<IRBlockEndNode>();
  falseIR.lock()->next = endElse;
  // 10 = rbrace
  auto mergeNode = std::make_shared<IRMergeNode>();
  endIf->next = mergeNode;
  endElse->next = mergeNode;
  conditionalNode->next = mergeNode;
  return { mergeNode, NO_VR };
}

TO_IR(WhileStatement) {
  // 0 = while
  // 1 = lparen
  // 2 = Expr
  auto conditionStart = std::make_shared<IRBlockStartNode>();
  auto [conditionIR, conditionVR] = m_children[2]->convertToIR(vsm, conditionStart);
  // 3 = rparen
  // Create the IRLoopNode
  auto loopNode = std::make_shared<IRLoopNode>();
  loopNode->conditionIR = conditionStart;
  loopNode->conditionVR = conditionVR;
  prev.lock()->next = loopNode;
  // 4 = lbrace
  // 5 = Block
  auto body = std::make_shared<IRBlockStartNode>();
  loopNode->body = body;
  auto [bodyIR, bodyVR] = m_children[5]->convertToIR(vsm, body);
  auto end = std::make_shared<IRLoopEndNode>();
  bodyIR.lock()->next = end;
  end->loop = loopNode;
  // 6 = rbrace
  auto mergeNode = std::make_shared<IRMergeNode>();
  end->next = mergeNode;
  loopNode->next = mergeNode;
  return { mergeNode, NO_VR };
}

std::shared_ptr<dlang::IRNode> Compiler::convertToIR(std::unique_ptr<dlang::ASTNode>&& ast) {
  auto entrypoint = std::make_shared<dlang::IRStartNode>();
  ast->convertToIR(vsm, entrypoint);
  return std::move(entrypoint);
}

void Compiler::compileIRToAssembly(std::shared_ptr<dlang::IRNode>&& ir, std::ostream& asm_out) {
  RegisterAllocator ra(ARM64NumFreeRegs, vsm.getNumVariables());
  ir->makeLivenessPass(vsm, ra);
  std::cerr << INFO("Generated IR:") << std::endl;
  ir->dump(std::cerr);
  std::cerr << std::endl << std::endl;

  ra.allocateRegisters();
  std::cerr << INFO("Register allocations:") << std::endl;
  for (unsigned vr = 0; vr < vsm.getNumVariables(); ++vr) {
    std::cerr << "allocating " << vr << " to register " << ra.getAllocationFor(vr) << std::endl;
  }
  std::cerr << std::endl;

  ir->toAssembly(ra, asm_out);
}
