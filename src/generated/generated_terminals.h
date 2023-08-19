#define FOR_EACH_TERMINAL(m) \
    m(delim,R"(^;)") \
    m(return,R"(^return)") \
    m(assign,R"(^=)") \
    m(num,R"(^\-?[0-9]+)") \
    m(ident,R"(^[a-zA-Z_]+)") \
    m(plus,R"(^\+)") \
    m(multiply,R"(^\*)") \

