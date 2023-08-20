
#ifndef _DCC_ARM64_H
#define _DCC_ARM64_H

#include <bitset>
#include <iostream>
#include <stdint.h>

#include "tokens.h"

namespace dlang {
enum Operator {
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  AND,
  OR,
  XOR,
  LSHIFT,
  RSHIFT
};

inline Operator toOperatorStruct(Token tok) {
  if (tok.value == "+") return PLUS;
  if (tok.value == "-") return MINUS;
  if (tok.value == "*") return MULTIPLY;
  if (tok.value == "/") return DIVIDE;
  if (tok.value == "&") return AND;
  if (tok.value == "|") return OR;
  if (tok.value == "^") return XOR;
  if (tok.value == "<<") return LSHIFT;
  if (tok.value == ">>") return RSHIFT;
  ERR_AND_EXIT("Invalid operator");
}

inline int evaluateOperator(int lhs, Operator op, int rhs) {
  switch(op) {
  case PLUS:
    return lhs + rhs;
  case MINUS:
    return lhs - rhs;
  case MULTIPLY:
    return lhs * rhs;
  case DIVIDE:
    return lhs / rhs;
  case AND:
    return lhs & rhs;
  case OR:
    return lhs | rhs;
  case XOR:
    return lhs ^ rhs;
  case LSHIFT:
    return lhs << rhs;
  case RSHIFT:
    return lhs >> rhs;
  default:
    UNREACHABLE("Invalid ARM64Operation operation type");
  }
}
}

std::ostream& operator<<(std::ostream& os, dlang::Operator op);

struct ARM64Register {
  bool isConst;
  unsigned reg;
  int value;
};

#define ARM64ReturnRegister ARM64Register { false, 0 }
#define ARM64TempRegister ARM64ReturnRegister
#define ARM64NumFreeRegs 16
#define REG(x) { false, x }
#define CONST(x) { true, 0, x }

using ARMRegisterUsed = std::bitset<32>;

#define OUTPUT_TYPE(T) std::ostream& operator<<(std::ostream& os, T instr)

std::ostream& operator<<(std::ostream& os, ARM64Register reg);

struct ARM64Mov {
  ARM64Register lhs;
  ARM64Register rhs;
};

OUTPUT_TYPE(ARM64Mov);

struct ARM64Operation {
  ARM64Register dest;
  ARM64Register lhs;
  dlang::Operator op;
  ARM64Register rhs;
};

OUTPUT_TYPE(ARM64Operation);

struct ARM64Return {
};

OUTPUT_TYPE(ARM64Return);

struct ARM64Label {
  unsigned value;
};

OUTPUT_TYPE(ARM64Label);

struct ARM64UnconditionalJump {
  ARM64Label target;
};

OUTPUT_TYPE(ARM64UnconditionalJump);

struct ARM64BranchIfNonZero {
  ARM64Register value;
  ARM64Label target;
};

OUTPUT_TYPE(ARM64BranchIfNonZero);

#endif
