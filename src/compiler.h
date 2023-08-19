
#ifndef _DCC_COMPILER_H
#define _DCC_COMPILER_H

#include "ast.h"
#include "compiler_context.h"
#include "ir.h"
#include "register_allocator.h"

class Compiler {
 public:
  Compiler()
    {}

  void compile(std::unique_ptr<dlang::ASTNode>&& ast, std::ostream& asm_out) {
    auto res = convertToIR(std::move(ast));
    compileIRToAssembly(std::move(res), asm_out);
  }

 private:
  std::shared_ptr<dlang::IRNode> convertToIR(std::unique_ptr<dlang::ASTNode>&& ast);
  void compileIRToAssembly(std::shared_ptr<dlang::IRNode>&& ir, std::ostream& asm_out);

  dlang::VariableScopeManager vsm;
};

#endif
