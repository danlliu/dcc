
CXX := g++ -std=c++17 -O3 -Wall -Werror -Wconversion
CXX_DBG := g++ -std=c++17 -g3 -Wall -Werror -Wconversion
INC := -I src

SPEC := spec/spec.txt

DCC_SRCS := $(wildcard src/*.cpp)
DCC_GENERATED_HEADERS := src/generated/generated_parser.h src/generated/generated_terminals.h

DCC_EXE := dcc

$(DCC_EXE): $(DCC_SRCS) gen $(DCC_GENERATED_HEADERS)
	$(CXX) $(INC) -o $@ $(DCC_SRCS)

$(DCC_EXE)_debug: $(DCC_SRCS) gen $(DCC_GENERATED_HEADERS)
	$(CXX_DBG) $(INC) -o $@ $(DCC_SRCS)

yadda: yadda.cpp
	$(CXX) $(INC) -o $@ $^

yadda_debug: yadda.cpp
	$(CXX_DBG) $(INC) -o $@ $^

.PHONY: gen
gen: yadda spec/spec.txt
	./yadda $(SPEC)

debug: $(DCC_EXE)_debug

.PHONY: clean
clean:
	@rm -f $(DCC_EXE)
	@rm -f $(DCC_EXE)_debug
	@rm -rf $(DCC_EXE)_debug.dSYM
	@rm -f yadda
	@rm -f yadda_debug
	@rm -rf yadda_debug.dSYM
