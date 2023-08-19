
#ifndef _DCC_TOKENS_H
#define _DCC_TOKENS_H

#include <ostream>
#include <string>
#include <utility>
#include <variant>

#include "macros.h"

#include "generated/generated_terminals.h"

namespace dlang {

#define TOKEN_NAME(name, regex) Token_##name,
enum TokenType {
  FOR_EACH_TERMINAL(TOKEN_NAME)
};

struct Token {
  std::string value;
  dlang::TokenType type;
};

};

std::ostream& operator<<(std::ostream& os, const dlang::Token& tok);

#endif
