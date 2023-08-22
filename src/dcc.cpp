#define DUMP_TOKENS 1
#define DUMP_AST 2
#define DUMP_IR 3
#define DUMP_REGISTER_ALLOCATION 4

#include <fstream>
#include <getopt.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

#include "compiler.h"
#include "macros.h"
#include "parser.h"
#include "tokenizer.h"
#include "tokens.h"

struct Option {
  static std::string outputFile;
  static bool dumpTokens;
  static bool dumpAST;
  static bool dumpIR;
  static bool dumpRegisterAllocation;
};

int main(int argc, char** argv) {
  Option options;
  if (argc < 2) ERR_AND_EXIT("Usage: " << argv[0] << "(options) <file.dlang>");
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

  while ((choice = getopt_long(argc, argv, "o", long_options, &option_index)) != -1) {
    switch (choice) {
      case 'o':
        options.outputFile = optarg;
        break;
      case DUMP_TOKENS:
        options.dumpTokens = true;
        break;
      case DUMP_AST: {
        options.dumpAST = true;
        break;
      }
      case DUMP_IR: {
        options.dumpIR = true;
        break;
      }
      case DUMP_REGISTER_ALLOCATION: {
        options.dumpRegisterAllocation = true;
        break;
      }
      default:
        std::cerr << "Error: Unknown command line option" << std::endl;
        exit(1);
    }
  }
  auto inFile = std::ifstream(argv[1]);
  std::string contents { std::istream_iterator<char>(inFile), std::istream_iterator<char>() };
  Tokenizer t(contents);
  auto res = t.tokenize();
  std::cerr << INFO("Tokens: ") << std::endl;
  for (auto t : res) std::cerr << t << " ";
  std::cerr << std::endl << std::endl;

  std::cerr << INFO("Parsed AST: ") << std::endl;
  Parser p(res);
  auto parsed = std::move(p.parse());
  parsed->dump(std::cerr);
  std::cerr << std::endl << std::endl;

  Compiler c;
  c.compile(std::move(parsed), std::cout);
}
