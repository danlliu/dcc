
#include "tokens.h"

using namespace dlang;

std::ostream& operator<<(std::ostream& os, const Token& tok) {
  return os << tok.value;
}