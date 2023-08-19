
#ifndef _DCC_AST_H
#define _DCC_AST_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "compiler_context.h"
#include "ir.h"
#include "macros.h"
#include "tokens.h"

namespace dlang {

struct IRResult {
  std::weak_ptr<dlang::IRNode> ir_last;
  VirtualRegister result;
};

#include "generated/generated_ast_type.h"

class ASTNode {
 public:
  ASTNode() {};
  virtual ~ASTNode() {};

  virtual std::ostream& dump(std::ostream& o) = 0;
  virtual ASTNodeType type() = 0;
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) = 0;

  inline void addChild(std::unique_ptr<ASTNode>&& p) { m_children.emplace_back(std::move(p)); }
  const std::vector<std::unique_ptr<ASTNode>>& children() const { return m_children; }
  inline const Token& token() const { return m_token; }
 protected:
  ASTNode(Token tok) : m_token(tok) {}
  std::vector<std::unique_ptr<ASTNode>> m_children;
  Token m_token;
};

#include "generated/generated_ast.h"

};

#endif
