
#include "tokenizer.h"

#include <string>

#include "generated/generated_terminals.h"
#include "macros.h"
#include "tokens.h"

#define TOKEN_CASES if (false) do {} while(0)
#define TOKEN_CASE(name, regex) else if ((res = parseToken_##name())) result.push_back(*res);
#define ELSE_TOKEN_NOT_FOUND else UNREACHABLE("Could not parse a token!")

Tokenizer::TokenStream Tokenizer::tokenize() {
  TokenStream result;
  while (m_curr != m_contents.cend()) {
    TokenResult res;
    TOKEN_CASES;
    FOR_EACH_TERMINAL(TOKEN_CASE)
    ELSE_TOKEN_NOT_FOUND;
  }
  return result;
}

void Tokenizer::skipWhitespace() {
  while (isWhitespace(*m_curr)) ++m_curr;
}

#define PARSER_MEMBER_FUNCTION(name, re) \
Tokenizer::TokenResult Tokenizer::parseToken_##name() { \
  skipWhitespace(); \
  std::regex r(re); \
  std::match_results<std::deque<char>::const_iterator> match; \
  if (std::regex_search(m_curr, m_contents.cend(), match, r)) { \
    m_curr = match[0].second; \
    return {{match[0], dlang::TokenType::Token_##name}}; \
  } \
  return {}; \
}

FOR_EACH_TERMINAL(PARSER_MEMBER_FUNCTION)
