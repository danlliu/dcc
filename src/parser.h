
#ifndef _DCC_PARSER_H
#define _DCC_PARSER_H

#include "ast.h"

#include <deque>

#include "tokenizer.h"
#include "tokens.h"

class Parser {
 public:
  Parser(const Tokenizer::TokenStream& tokens)
    : m_tokens(tokens)
    {}

  std::unique_ptr<dlang::ASTNode>&& parse();

 private:

  inline void pushASTNode(std::unique_ptr<dlang::ASTNode>&& n) { m_parseTrees.emplace_front(std::move(n)); }
  inline std::unique_ptr<dlang::ASTNode>&& popASTNode() {
    std::unique_ptr<dlang::ASTNode> node = std::move(m_parseTrees.front());
    m_parseTrees.pop_front();
    return std::move(node);
  }

  inline dlang::Token peek() {
    return *m_curr;
  }

  inline void shift() {
    m_curr++;
  }

  inline void reduce(std::unique_ptr<dlang::ASTNode>&& p, size_t k) {
    std::stack<std::unique_ptr<dlang::ASTNode>> inversion;
    for (size_t i = 0; i < k; ++i) {
      inversion.emplace(std::move(m_parseTrees.front()));
      m_parseTrees.pop_front();
      m_states.pop();
    }
    while (size(inversion)) {
      p->addChild(std::move(inversion.top()));
      inversion.pop();
    }
    pushASTNode(std::move(p));
  }

  inline bool eof() {
    return m_curr == end(m_tokens);
  }

  Tokenizer::TokenStream m_tokens;
  Tokenizer::TokenStream::iterator m_curr;
  std::deque<std::unique_ptr<dlang::ASTNode>> m_parseTrees;
  std::stack<size_t> m_states;
};

#endif
