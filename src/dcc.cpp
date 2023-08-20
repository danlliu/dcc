
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

#include "compiler.h"
#include "macros.h"
#include "parser.h"
#include "tokenizer.h"
#include "tokens.h"

int main(int argc, char** argv) {
  if (argc != 2)
    ERR_AND_EXIT("Usage: " << argv[0] << " <file.dlang>");
  auto inFile = std::ifstream(argv[1]);
  std::string contents{std::istream_iterator<char>(inFile), std::istream_iterator<char>()};
  Tokenizer t(contents);
  auto res = t.tokenize();
  for (auto t : res)
    std::cout << t << " ";
  std::cout << std::endl;

  Parser p(res);
  auto parsed = std::move(p.parse());
  parsed->dump(std::cout);
  std::cout << std::endl;

  Compiler c;
  c.compile(std::move(parsed), std::cout);
}
