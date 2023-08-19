
// yadda: yacc but macro (don't ask where the a came from)
// yet another deranged daniel automation?

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <unordered_map>

#define TERMINAL_FILENAME "src/generated/generated_terminals.h"
#define AST_TYPE_FILENAME "src/generated/generated_ast_type.h"
#define AST_FILENAME "src/generated/generated_ast.h"
#define PARSER_FILENAME "src/generated/generated_parser.h"

struct Terminal {
  std::string regex;
};

struct Nonterminal { };

struct ProductionRule {
  std::string lhs;
  std::vector<std::string> tokens;
};

std::ostream& operator<<(std::ostream& os, ProductionRule item) {
  os << item.lhs << " -> ";
  for (size_t i = 0; i < size(item.tokens); ++i) {
    os << item.tokens[i] << " ";
  }
  return os;
}

struct LRItem {
  std::string lhs;
  std::vector<std::string> tokens;
  size_t position;
  int ruleIndex;
};

std::ostream& operator<<(std::ostream& os, LRItem item) {
  os << item.lhs << " -> ";
  for (size_t i = 0; i < size(item.tokens); ++i) {
    if (i == item.position) {
      os << "# ";
    }
    os << item.tokens[i] << " ";
  }
  if (item.position == size(item.tokens)) {
    os << "# ";
  }
  os << " (from rule index " << item.ruleIndex << ")";
  return os;
}

using LRItemSet = std::vector<LRItem>;

struct LRTableRow {
  std::unordered_map<std::string, size_t> jumps;
  std::unordered_map<std::string, size_t> gotos;
  int reduce = -1;
  bool eof = false;
};

std::ostream& operator<<(std::ostream& os, LRTableRow row) {
  os << "LRTableRow {\n";
  if (row.reduce != -1) {
    os << "reduce r" << row.reduce << "\n";
  } else {
    for (auto [name, idx] : row.jumps) os << "  " << name << ": goto " << idx << "\n";
    for (auto [name, idx] : row.gotos) os << "  " << name << ": goto " << idx << "\n";
  }
  os << "}";
  return os;
}

class YaddaParser {
 public:
  YaddaParser(std::ifstream &ifs)
    : m_if(ifs)
    {}
  
  void parse();
 private:
  inline bool isTerminal(const std::string& name) {
    return m_terminals.find(name) != m_terminals.end();
  }
  inline bool isNonTerminal(const std::string& name) {
    return m_nonterminals.find(name) != m_nonterminals.end();
  }
 
  std::ifstream &m_if;

  enum Assoc {
    LEFT,
    RIGHT,
    NONE,
  };

  inline Assoc parseAssociativity(const std::string& name) {
    if (name == "left") return LEFT;
    if (name == "right") return RIGHT;
    if (name == "none") return NONE;
    assert(false);
  }

  struct PrecedenceAssoc {
    unsigned long precedence;
    Assoc associativity;
  };

  std::unordered_map<std::string, Terminal> m_terminals;
  std::unordered_map<std::string, Nonterminal> m_nonterminals;
  std::unordered_map<std::string, PrecedenceAssoc> m_precedences;
  std::vector<ProductionRule> m_productionRules;
  std::unordered_multimap<std::string, size_t> m_productionRulesForLHS;
};

void YaddaParser::parse() {
  {
    // Parsing terminals
    // Output part 1: FOR_EACH_TERMINAL higher-order macro
    std::ofstream terminals(TERMINAL_FILENAME);

    terminals << R"(#define FOR_EACH_TERMINAL(m) \)" << std::endl;

    std::string line;
    while (std::getline(m_if, line)) {
      if (line[0] == '#') continue;
      if (line == "%%") break;
      std::smatch match;
      if (std::regex_match(line, match, std::regex{R"(([a-z][A-Za-z]*) (.*))"})) {
        m_terminals[match[1]] = {match[2]};
        terminals << "    m(" << match[1] << "," << "R\"(^" << match[2] << ")\") \\\n";
      }
      else {
        std::cerr << "Invalid terminal name (must be all lower case)" << std::endl;
        exit(1);
      }
    }

    terminals << std::endl;
  }
  std::cout << "Found " << size(m_terminals) << " terminals" << std::endl;
  {
    // Parsing terminal precedence
    std::string line;
    while (std::getline(m_if, line)) {
      if (line[0] == '#') continue;
      if (line == "%%") break;
      std::smatch match;
      if (std::regex_match(line, match, std::regex{R"(([a-z][A-Za-z]*) ([0-9]+) (left|right|none))"})) {
        auto name = match[1];
        auto precedence = std::stoul(match[2]);
        auto associativity = parseAssociativity(match[3]);
        if (!isTerminal(name)) {
          std::cerr << "Invalid terminal found in precedence: " << name << std::endl;
          exit(1);
        }
        m_precedences[name] = {precedence, associativity};
      }
      else {
        std::cerr << "Invalid precedence line (expected terminal precedence associativity)" << std::endl;
        exit(1);
      }
    }
  }
  std::string target = "";
  {
    // Parsing non-terminals
    std::string line;
    while (std::getline(m_if, line)) {
      if (line[0] == '#') continue;
      if (line == "%%") break;
      if (target == "") target = line;
      if (std::regex_match(line, std::regex{R"([A-Z][A-Za-z]*)"}))
        m_nonterminals[line] = {};
      else {
        std::cerr << "Invalid nonterminal name (must start with capital letter)" << std::endl;
        exit(1);
      }
    }
  }
  std::cout << "Found " << size(m_nonterminals) << " non-terminals" << std::endl;
  {
    // Parse production rules
    std::string line;
    while (std::getline(m_if, line)) {
      if (line[0] == '#') continue;
      std::smatch match;
      std::regex_match(line, match, std::regex(R"(([A-Za-z]+) \-> (.*))"));
      std::regex tokenRegex("[A-Za-z]+");
      std::string tokens = match[2];
      auto wordBegin = std::sregex_iterator(begin(tokens), end(tokens), tokenRegex);
      auto wordEnd = std::sregex_iterator();
      std::vector<std::string> words;
      std::for_each(wordBegin, wordEnd, [&](auto it){words.emplace_back(it.str());});
      m_productionRules.push_back({match[1], words});
      m_productionRulesForLHS.emplace(match[1], size(m_productionRules) - 1);
    }
  }

  {
    // Output part 2: AST types and nodes
    std::ofstream ast_types(AST_TYPE_FILENAME);
    std::ofstream ast_nodes(AST_FILENAME);
    ast_nodes << "#define AST_NODE_NAME_FOR_TYPE(x) ASTNode_##x\n";
    ast_nodes << "#define AST_NODE_NAME_FOR_TYPE_STR(x) \"ASTNode_\" #x\n";

    ast_types << "enum ASTNodeType {\n";
    auto generateEnumCase = [&](std::string name) {
      ast_types << "  ASTNodeType_" << name << ",\n";
    };
    for (auto [name, _] : m_terminals)
      generateEnumCase(name);
    for (auto [name, _] : m_nonterminals)
      generateEnumCase(name);
    ast_types << "};\n";
    
    auto generateASTNodeClass = [&](std::string name, bool terminal) {
      ast_nodes << "class AST_NODE_NAME_FOR_TYPE(" << name << ") : public ASTNode {\n";
      ast_nodes << " public:\n";
      if (terminal)
        ast_nodes << "  AST_NODE_NAME_FOR_TYPE(" << name << ")(Token token)\n";
      else
        ast_nodes << "  AST_NODE_NAME_FOR_TYPE(" << name << ")()\n";
      if (terminal)
        ast_nodes << "  : ASTNode(token)\n";
      ast_nodes << "  {}\n";
      ast_nodes << "  virtual std::ostream& dump(std::ostream& o) override {\n";
      if (terminal) {
        ast_nodes << "    o << AST_NODE_NAME_FOR_TYPE_STR(" << name << ") \" { \" << m_token << \" }\";\n";
      }
      else {
        ast_nodes << "    o << AST_NODE_NAME_FOR_TYPE_STR(" << name << ") \" { \";\n";
        ast_nodes << "    for (auto&& c : m_children) {\n";
        ast_nodes << "      c->dump(o);\n";
        ast_nodes << "      o << \" \";\n";
        ast_nodes << "    }\n";
        ast_nodes << "    o << \" } \";\n";
      }
      ast_nodes << "    return o;\n";
      ast_nodes << "  }\n";
      ast_nodes << "  virtual ASTNodeType type() override { return ASTNodeType::ASTNodeType_" << name << "; }\n";
      ast_nodes << "  virtual IRResult convertToIR(VariableScopeManager&, std::weak_ptr<dlang::IRNode>) override;\n";
      ast_nodes << " private:\n";
      ast_nodes << "};\n";
    };
    for (auto [name, _] : m_terminals)
      generateASTNodeClass(name, true);
    for (auto [name, _] : m_nonterminals)
      generateASTNodeClass(name, false);
  }

  {
    // Output part 3: parser
    std::ofstream parser(PARSER_FILENAME);

    // TokenType: generate token type enum name
    parser << "#ifndef TOKENTYPE\n";
    parser << "#define TOKENTYPE() static_assert(false, \"Must declare macro TOKENTYPE for the macro parser\")\n";
    parser << "#endif\n";

    // State: get the current state by reference
    parser << "#ifndef STATE\n";
    parser << "#define STATE() static_assert(false, \"Must declare macro STATE for the macro parser\")\n";
    parser << "#endif\n";

    // PushState
    parser << "#ifndef PUSHSTATE\n";
    parser << "#define PUSHSTATE(x) static_assert(false, \"Must declare macro PUSHSTATE for the macro parser\")\n";
    parser << "#endif\n";

    // IS_EOF: is at IS_EOF
    parser << "#ifndef IS_EOF\n";
    parser << "#define IS_EOF() static_assert(false, \"Must declare macro IS_EOF for the macro parser\")\n";
    parser << "#endif\n";

    // Peek: look at the next token
    parser << "#ifndef PEEK\n";
    parser << "#define PEEK() static_assert(false, \"Must declare macro PEEK for the macro parser\")\n";
    parser << "#endif\n";

    // Shift: move forward one token
    parser << "#ifndef SHIFT\n";
    parser << "#define SHIFT(x) static_assert(false, \"Must declare macro SHIFT for the macro parser\")\n";
    parser << "#endif\n";

    // Reduce: reduce items into a higher level node
    parser << "#ifndef REDUCE\n";
    parser << "#define REDUCE(T, n) static_assert(false, \"Must declare macro REDUCE for the macro parser\")\n";
    parser << "#endif\n";

    // Success
    parser << "#ifndef SUCCESS\n";
    parser << "#define SUCCESS() static_assert(false, \"Must declare macro SUCCESS for the macro parser\")\n";
    parser << "#endif\n";

    // Failure
    parser << "#ifndef FAILURE\n";
    parser << "#define FAILURE() static_assert(false, \"Must declare macro FAILURE for the macro parser\")\n";
    parser << "#endif\n";

    auto closure = [&](LRItemSet& itemSet) {
      std::vector<bool> addedToClosure(size(m_productionRules), false);
      for (auto r : itemSet) if (r.ruleIndex != -1) addedToClosure[static_cast<size_t>(r.ruleIndex)] = true;
      for (size_t i = 0; i < size(itemSet); ++i) {
        LRItem& item = itemSet[i];
        if (item.position == size(item.tokens)) continue;
        auto nextTok = item.tokens[item.position];
        if (isNonTerminal(nextTok)) {
          auto [beginIt, endIt] = m_productionRulesForLHS.equal_range(nextTok);
          for (auto it = beginIt; it != endIt; ++it) {
            ProductionRule& pr = m_productionRules[it->second];
            if (!addedToClosure[it->second]) {
              itemSet.emplace_back(LRItem{pr.lhs, pr.tokens, 0, static_cast<int>(it->second)});
              addedToClosure[it->second] = true;
            }
          }
        }
      }
    };

    std::deque<LRItemSet> itemSets;
    {
      std::vector<std::string> initTokens(2);
      initTokens[0] = target;
      initTokens[1] = "_EOF";
      LRItemSet initial(1, {"_START", initTokens, 0, -1});
      closure(initial);
      itemSets.emplace_back(initial);
    }

    std::vector<LRTableRow> lrTable;

    for (size_t i = 0; i < size(itemSets); ++i) {
      LRItemSet currSet = itemSets[i];
      
      // Logging
      std::cout << "Parsing item set " << i << std::endl << std::endl;
      for (auto lri : currSet) std::cout << lri << std::endl;

      int reduced = -1;
      bool foundEOF = false;

      // Find each symbol after #
      std::map<std::string, LRItemSet> newItemSets;
      for (auto lri : currSet) {
        if (lri.position != size(lri.tokens)) {
          if (lri.tokens[lri.position] != "_EOF") {
            LRItem advanced = lri;
            ++advanced.position;
            newItemSets[lri.tokens[lri.position]].push_back(advanced);
          } else
            foundEOF = true;
        } else {
          reduced = lri.ruleIndex;
        }
      }

      LRTableRow tr;
      tr.eof = foundEOF;
      if (reduced != -1) {
        tr.reduce = reduced;
        if (!newItemSets.empty()) {
          std::cerr << "Found Shift/Reduce conflict, attempting to resolve..." << std::endl;
          std::map<std::string, LRItemSet> resolvedItemSets;
          // Find operator terminal
          auto rule = m_productionRules[static_cast<unsigned>(reduced)];
          for (auto iter = rule.tokens.rbegin(); iter != rule.tokens.rend(); ++iter) {
            if (isTerminal(*iter)) {
              // found operator terminal
              std::cerr << "Found operator terminal = " << *iter << std::endl;
              auto operatorTerminal = m_precedences[*iter];
              std::cerr << "Precedence = " << operatorTerminal.precedence << std::endl;
              std::cerr << "Associativity = " << operatorTerminal.associativity << std::endl;
              for (auto [tok, val] : newItemSets) {
                auto shiftTerminal = m_precedences[tok];
                std::cerr << "  Examining shift terminal " << tok << std::endl;
                std::cerr << "  Precedence = " << shiftTerminal.precedence << std::endl;
                std::cerr << "  Associativity = " << shiftTerminal.associativity << std::endl;
                if (shiftTerminal.precedence > operatorTerminal.precedence) {
                  std::cerr << "  shift > operator: action is to shift" << std::endl;
                  resolvedItemSets[tok] = val;
                } else if (shiftTerminal.precedence == operatorTerminal.precedence) {
                  if (operatorTerminal.associativity == LEFT) {
                    std::cerr << "  shift == operator and left associative: action is to reduce" << std::endl;
                  } else if (operatorTerminal.associativity == RIGHT) {
                    std::cerr << "  shift == operator and right associative: action is to shift" << std::endl;
                    resolvedItemSets[tok] = val;
                  } else {
                    std::cerr << "  shift == operator and not associative: action is to syntax error" << std::endl;
                  }
                } else {
                  std::cerr << "  shift < operator: action is to reduce" << std::endl;
                }
              }
              goto safe;
            }
          }
          std::cerr << "Shift/Reduce conflict detected!" << std::endl;
          exit(1);
          safe:
          for (auto [tok, set] : resolvedItemSets) {
            closure(set);
            if (isTerminal(tok))
              tr.jumps[tok] = size(itemSets);
            else if (isNonTerminal(tok))
              tr.gotos[tok] = size(itemSets);
            itemSets.emplace_back(set);
          }
        }
      } else {
        for (auto [tok, set] : newItemSets) {
          closure(set);
          if (isTerminal(tok))
            tr.jumps[tok] = size(itemSets);
          else if (isNonTerminal(tok))
            tr.gotos[tok] = size(itemSets);
          itemSets.emplace_back(set);
        }
      }
      lrTable.emplace_back(tr);
    }

    std::cout << "Generated table:" << std::endl;
    int state = 0;
    for (auto r : lrTable) {
      std::cout << state++ << ": " << r << std::endl;
    }

    std::unordered_map<std::string, std::map<size_t, size_t>> gotoLookup;
    for (size_t i = 0; i < size(lrTable); ++i) {
      auto r = lrTable[i];
      for (auto [type, target] : r.gotos) {
        gotoLookup[type][i] = target;
      }
    }

    // Generate macro parser
    parser << "if (false) {}\n";
    for (size_t i = 0; i < size(lrTable); ++i) {
      auto row = lrTable[i];
      parser << "else if (STATE() == " << i << ") {\n";

      if (row.reduce == -1) {
        parser << "  if (IS_EOF()) " << (row.eof ? "SUCCESS()" : "FAILURE()") << ";\n";
      }
      parser << "  if (false) {}\n";
      for (auto [type, target] : row.jumps) {
        parser << "  else if (PEEK().type == TOKENTYPE(" << type << ")) { SHIFT(" << type << "); PUSHSTATE(" << target << ");}\n";
      }
      if (row.reduce != -1) {
        auto rule = m_productionRules[static_cast<size_t>(row.reduce)];
        parser << "  else {\n";
        parser << "    REDUCE(" << rule.lhs << ", " << size(rule.tokens) << ");\n";
        parser << "    if (false) {}\n";
        for (auto [curr, target] : gotoLookup[rule.lhs])
          parser << "    else if (STATE() == " << curr << ") PUSHSTATE(" << target << ");\n";
        parser << "  }\n";
      } else {
        parser << "  else FAILURE();\n";
      }
      parser << "}\n";

      // if (row.reduce != -1) {
      //   // Reduce
      //   auto rule = m_productionRules[static_cast<size_t>(row.reduce)];
      //   parser << "  REDUCE(" << rule.lhs << ", " << size(rule.tokens) << ");\n";
      //   // Goto table
      //   parser << "  if (false) {}\n";
      //   for (auto [curr, target] : gotoLookup[rule.lhs])
      //     parser << "  else if (STATE() == " << curr << ") PUSHSTATE(" << target << ");\n";
      // } else {
      //   parser << "  if (IS_EOF()) " << (row.eof ? "SUCCESS()" : "FAILURE()") << ";\n";
      //   // Shift maybe
      //   parser << "  if (false) {}\n";
      //   for (auto [type, target] : row.jumps) {
      //     parser << "  else if (PEEK().type == TOKENTYPE(" << type << ")) { SHIFT(" << type << "); PUSHSTATE(" << target << ");}\n";
      //   }
      //   parser << "  else FAILURE();\n";
      // }
      // parser << "}\n";
    }
    parser << "else UNREACHABLE(\"Invalid parser state\");\n";
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <spec>" << std::endl;
    return 1;
  }
  std::ifstream ifs(argv[1]);
  YaddaParser(ifs).parse();
}
