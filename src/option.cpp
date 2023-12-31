#define DUMP_TOKENS 1
#define DUMP_AST 2
#define DUMP_IR 3
#define DUMP_REGISTER_ALLOCATION 4

#include "option.h"

#include <getopt.h>
#include <iostream>
#include <string>

std::string Option::outputFile = "out.txt";
bool Option::dumpTokens = false;
bool Option::dumpAST = false;
bool Option::dumpIR = false;
bool Option::dumpRegisterAllocation = false;

void getOptions(int argc, char** argv) {
  int choice;
  int option_index = 0;
  option long_options[]{
    {"output",                      required_argument, nullptr, 'o'},
    {"dump-tokens",                 no_argument,       nullptr, DUMP_TOKENS},
    {"dump-ast",                    no_argument,       nullptr, DUMP_AST},
    {"dump-ir",                     no_argument,       nullptr, DUMP_IR},
    {"dump-register-allocation",    no_argument,       nullptr, DUMP_REGISTER_ALLOCATION},
    {nullptr,                       0,                 nullptr, '\0'}
  };

  while ((choice = getopt_long(argc, argv, "o:", long_options, &option_index)) != -1) {
    switch (choice) {
      case 'o':
        Option::outputFile = optarg;
        break;
      case DUMP_TOKENS:
        Option::dumpTokens = true;
        break;
      case DUMP_AST: {
        Option::dumpAST = true;
        break;
      }
      case DUMP_IR: {
        Option::dumpIR = true;
        break;
      }
      case DUMP_REGISTER_ALLOCATION: {
        Option::dumpRegisterAllocation = true;
        break;
      }
      default:
        std::cerr << "Error: Unknown command line option" << std::endl;
        exit(1);
    }
  }
}
