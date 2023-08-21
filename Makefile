
CXX := g++ -std=c++17 -O3 -Wall -Werror -Wconversion
CXX_DBG := g++ -std=c++17 -g3 -Wall -Werror -Wconversion
INC := -I src

SPEC := spec/spec.txt

GENERATED_FLAG_FILE := src/generated/generated

DCC_SRCS := $(wildcard src/*.cpp)
DCC_HEADERS := $(wildcard src/*.h)
DCC_GENERATED_HEADERS := src/generated/generated_ast_type.h src/generated/generated_ast.h src/generated/generated_parser.h src/generated/generated_terminals.h

DCC_EXE := dcc

$(DCC_EXE): $(DCC_SRCS) $(DCC_HEADERS) $(GENERATED_FLAG_FILE)
	$(CXX) $(INC) -o $@ $(DCC_SRCS)

$(DCC_EXE)_debug: $(DCC_SRCS) $(DCC_HEADERS) $(GENERATED_FLAG_FILE)
	$(CXX_DBG) $(INC) -o $@ $(DCC_SRCS)

yadda: yadda.cpp
	$(CXX) $(INC) -o $@ $^

yadda_debug: yadda.cpp
	$(CXX_DBG) $(INC) -o $@ $^

$(GENERATED_FLAG_FILE): yadda spec/spec.txt
	@mkdir -p src/generated
	./yadda $(SPEC)
	@touch $(GENERATED_FLAG_FILE)

debug: $(DCC_EXE)_debug

runtime/main.o: runtime/main.cpp
	$(CXX) -o $@ -c $^

.PHONY: clean
clean:
	@rm -f $(DCC_EXE)
	@rm -f $(DCC_EXE)_debug
	@rm -rf $(DCC_EXE)_debug.dSYM
	@rm -f yadda
	@rm -f yadda_debug
	@rm -rf yadda_debug.dSYM
	@rm -f $(DCC_GENERATED_HEADERS)
	@rm -f src/generated/generated
