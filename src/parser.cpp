
#include "parser.h"

#include <memory>
#include <stack>

#include "ast.h"
#include "macros.h"
#include "tokens.h"

using namespace dlang;

std::unique_ptr<dlang::ASTNode>&& Parser::parse() {
  // LR Loop
#define TOKENTYPE(x) dlang::TokenType::Token_##x
#define STATE() m_states.top()
#define PUSHSTATE(x) m_states.push(x)
#define IS_EOF() eof()
#define PEEK() peek()
#define SHIFT(T)                                                                               \
  do {                                                                                         \
    std::unique_ptr<dlang::ASTNode> lhs = std::make_unique<AST_NODE_NAME_FOR_TYPE(T)>(peek()); \
    pushASTNode(std::move(lhs));                                                               \
    shift();                                                                                   \
  } while (0)
#define REDUCE(T, x)                                                                     \
  do {                                                                                   \
    std::unique_ptr<dlang::ASTNode> lhs = std::make_unique<AST_NODE_NAME_FOR_TYPE(T)>(); \
    reduce(std::move(lhs), x);                                                           \
  } while (0)
#define SUCCESS() break
#define FAILURE()                              \
  do {                                         \
    std::cerr << "Syntax error!" << std::endl; \
    exit(1);                                   \
  } while (0)

  m_states.push(0);
  m_curr = begin(m_tokens);
  while (1) {
#include "generated/generated_parser.h"
  }

  return std::move(m_parseTrees.front());
}
