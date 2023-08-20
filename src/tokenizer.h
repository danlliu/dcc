
#ifndef _DCC_TOKENIZER_H
#define _DCC_TOKENIZER_H

#include <deque>
#include <optional>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "generated/generated_terminals.h"
#include "tokens.h"

class Tokenizer {
  public:
  Tokenizer(std::string contents)
      : m_contents(begin(contents), end(contents))
      , m_curr(m_contents.cbegin()) {};

  using TokenResult = std::optional<dlang::Token>;
  using TokenStream = std::vector<dlang::Token>;

  TokenStream tokenize();

  private:
  inline bool isWhitespace(char c) { return c == ' ' || c == '\t' || c == '\n'; }

  void skipWhitespace();

#define PARSE_FN_DECL(name, regex) TokenResult parseToken_##name();
  FOR_EACH_TERMINAL(PARSE_FN_DECL);

  using ParserState = int;

  // Member variables
  std::deque<char> m_contents;
  std::stack<ParserState> states;
  std::deque<char>::const_iterator m_curr;
};

#endif
