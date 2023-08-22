#include <string>

struct Option {
  static std::string outputFile;
  static bool dumpTokens;
  static bool dumpAST;
  static bool dumpIR;
  static bool dumpRegisterAllocation;
};