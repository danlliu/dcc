#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

#include "compiler.h"
#include "macros.h"
#include "option.h"
#include "parser.h"
#include "tokenizer.h"
#include "tokens.h"

int main(int argc, char** argv) {
  if (argc < 2) ERR_AND_EXIT("Usage: " << argv[0] << " (options) <file.dlang>");
  getOptions(argc, argv);
  auto inFile = std::ifstream(argv[argc - 1]);
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
