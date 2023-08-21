
#include "arm64.h"

#include "macros.h"

using namespace dlang;

std::ostream& operator<<(std::ostream& os, ARM64Register reg) {
  if (reg.isConst)
    return os << "#" << reg.value;
  else
    return os << "x" << reg.reg;
}

std::ostream& operator<<(std::ostream& os, Operator op) {
  switch (op) {
  case PLUS:
    return os << "+";
  case MINUS:
    return os << "-";
  case MULTIPLY:
    return os << "*";
  case DIVIDE:
    return os << "/";
  case AND:
    return os << "&";
  case OR:
    return os << "|";
  case XOR:
    return os << "^";
  case LSHIFT:
    return os << "<<";
  case RSHIFT:
    return os << ">>";
  default:
    UNREACHABLE("Invalid ARM64Operation operation type");
  }
}

void ARM64Prelude(std::ostream &os) {
  os << ".align 4\n";
  os << ".global _dlang_start\n";
  os << "_dlang_start:\n";
}

OUTPUT_TYPE(ARM64Mov) {
  if (!instr.rhs.isConst && instr.lhs.reg == instr.rhs.reg) return os;
  return os << "  mov " << instr.lhs << ", " << instr.rhs << "\n";
}

OUTPUT_TYPE(ARM64Operation) {
  os << "  ";
  switch (instr.op) {
  case dlang::PLUS:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      return os << "add " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
    } else
      return os << "add " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::MINUS:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      os << "sub " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
      return os << "neg " << instr.dest << ", " << instr.dest << "\n";
    } else
      return os << "sub " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::MULTIPLY:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      return os << "mul " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
    } else
      return os << "mul " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::DIVIDE:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      os << "mov " << ARM64TempRegister << ", " << instr.lhs << "\n";
      return os << "sdiv " << instr.dest << ", " << ARM64TempRegister << ", " << instr.rhs << "\n";
    } else
      return os << "sdiv " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::AND:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      return os << "and " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
    } else
      return os << "and " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::OR:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      return os << "orr " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
    } else
      return os << "orr " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::XOR:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      return os << "xor " << instr.dest << ", " << instr.rhs << ", " << instr.lhs << "\n";
    } else
      return os << "xor " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::LSHIFT:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      os << "mov " << ARM64TempRegister << ", " << instr.lhs << "\n";
      return os << "lsl " << instr.dest << ", " << ARM64TempRegister << ", " << instr.rhs << "\n";
    } else
      return os << "lsl " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  case dlang::RSHIFT:
    if (instr.lhs.isConst) {
      if (instr.rhs.isConst) UNREACHABLE("Found two constants in operation... should have been folded");
      os << "mov " << ARM64TempRegister << ", " << instr.lhs << "\n";
      return os << "lsr " << instr.dest << ", " << ARM64TempRegister << ", " << instr.rhs << "\n";
    } else
      return os << "lsr " << instr.dest << ", " << instr.lhs << ", " << instr.rhs << "\n";
  default:
    UNREACHABLE("Invalid ARM64Operation operation type");
  }
}

OUTPUT_TYPE(ARM64Return) {
  return os << "  br lr\n";
}

OUTPUT_TYPE(ARM64Label) {
  return os << ".L" << instr.value;
}

OUTPUT_TYPE(ARM64LabelDefinition) {
  return os << instr.label << ":\n";
}

OUTPUT_TYPE(ARM64UnconditionalJump) {
  return os << "  b " << instr.target << "\n";
}

OUTPUT_TYPE(ARM64BranchIfZero) {
  return os << "  cbz " << instr.value << ", " << instr.target << "\n";
}

OUTPUT_TYPE(ARM64BranchIfNonZero) {
  return os << "  cbnz " << instr.value << ", " << instr.target << "\n";
}
