#define AST_NODE_NAME_FOR_TYPE(x) ASTNode_##x
#define AST_NODE_NAME_FOR_TYPE_STR(x) "ASTNode_" #x
class AST_NODE_NAME_FOR_TYPE(rshift) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(rshift)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(rshift) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_rshift; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(lparen) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(lparen)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(lparen) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_lparen; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(lshift) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(lshift)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(lshift) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_lshift; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(bitor) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(bitor)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(bitor) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_bitor; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(bitand) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(bitand)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(bitand) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_bitand; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(divide) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(divide)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(divide) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_divide; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(ident) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(ident)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(ident) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_ident; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(return) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(return)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(return) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_return; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(num) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(num)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(num) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_num; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(rparen) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(rparen)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(rparen) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_rparen; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(plus) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(plus)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(plus) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_plus; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(lbrace) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(lbrace)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(lbrace) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_lbrace; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(assign) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(assign)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(assign) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_assign; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(multiply) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(multiply)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(multiply) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_multiply; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(rbrace) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(rbrace)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(rbrace) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_rbrace; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(bitxor) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(bitxor)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(bitxor) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_bitxor; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(delim) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(delim)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(delim) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_delim; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(minus) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(minus)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(minus) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_minus; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(if) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(if)(Token token)
  : ASTNode(token)
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(if) " { " << m_token << " }";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_if; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(Expr) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(Expr)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(Expr) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_Expr; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(AssignStatement) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(AssignStatement)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(AssignStatement) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_AssignStatement; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(ReturnStatement) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(ReturnStatement)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(ReturnStatement) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_ReturnStatement; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(IfStatement) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(IfStatement)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(IfStatement) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_IfStatement; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(Statement) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(Statement)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(Statement) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_Statement; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
class AST_NODE_NAME_FOR_TYPE(Block) : public ASTNode {
 public:
  AST_NODE_NAME_FOR_TYPE(Block)()
  {}
  virtual std::ostream& dump(std::ostream& o) override {
    o << AST_NODE_NAME_FOR_TYPE_STR(Block) " { ";
    for (auto&& c : m_children) {
      c->dump(o);
      o << " ";
    }
    o << " } ";
    return o;
  }
  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_Block; }
  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;
 private:
};
