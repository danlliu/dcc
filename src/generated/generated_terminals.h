#define FOR_EACH_TERMINAL(m) \
    m(delim,R"(^;)") \
    m(return,R"(^return)") \
    m(assign,R"(^=)") \
    m(num,R"(^[0-9]+)") \
    m(ident,R"(^[a-zA-Z_]+)") \
    m(plus,R"(^\+)") \
    m(minus,R"(^\-)") \
    m(multiply,R"(^\*)") \
    m(divide,R"(^/)") \
    m(bitand,R"(^&)") \
    m(bitor,R"(^\|)") \
    m(bitxor,R"(^\^)") \
    m(lshift,R"(^<<)") \
    m(rshift,R"(^>>)") \

