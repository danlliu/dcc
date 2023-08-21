
#include "tokens.h"

using namespace dlang;

std::ostream& operator<<(std::ostream& os, Token const& tok) {
  return os << tok.value;
}