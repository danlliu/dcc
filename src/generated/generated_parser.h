#ifndef TOKENTYPE
#define TOKENTYPE() static_assert(false, "Must declare macro TOKENTYPE for the macro parser")
#endif
#ifndef STATE
#define STATE() static_assert(false, "Must declare macro STATE for the macro parser")
#endif
#ifndef PUSHSTATE
#define PUSHSTATE(x) static_assert(false, "Must declare macro PUSHSTATE for the macro parser")
#endif
#ifndef IS_EOF
#define IS_EOF() static_assert(false, "Must declare macro IS_EOF for the macro parser")
#endif
#ifndef PEEK
#define PEEK() static_assert(false, "Must declare macro PEEK for the macro parser")
#endif
#ifndef SHIFT
#define SHIFT(x) static_assert(false, "Must declare macro SHIFT for the macro parser")
#endif
#ifndef REDUCE
#define REDUCE(T, n) static_assert(false, "Must declare macro REDUCE for the macro parser")
#endif
#ifndef SUCCESS
#define SUCCESS() static_assert(false, "Must declare macro SUCCESS for the macro parser")
#endif
#ifndef FAILURE
#define FAILURE() static_assert(false, "Must declare macro FAILURE for the macro parser")
#endif
if (false) {}
else if (STATE() == 0) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(6);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(5);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 1) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else if (IS_EOF()) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 2) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(6);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(5);}
  else { if (IS_EOF()) SUCCESS(); }
}
else if (STATE() == 3) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else if (IS_EOF()) {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(7);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 4) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else if (IS_EOF()) {
    REDUCE(Block, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 5) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(assign)) { SHIFT(assign); PUSHSTATE(8);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 6) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 7) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 2);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 2);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else if (IS_EOF()) {
    REDUCE(Block, 2);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 8) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 9) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(17);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(23);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(14);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 10) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 11) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(24);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 12) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 13) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(23);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(14);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 14) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 15) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 16) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 17) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(ReturnStatement, 3);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(3);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(ReturnStatement, 3);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(3);
  }
  else if (IS_EOF()) {
    REDUCE(ReturnStatement, 3);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(3);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 18) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 19) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 20) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 21) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 22) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 23) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(12);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 24) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 2);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 25) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(AssignStatement, 4);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(1);
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(AssignStatement, 4);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(1);
  }
  else if (IS_EOF()) {
    REDUCE(AssignStatement, 4);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(1);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 26) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(23);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 27) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(23);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 28) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(23);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 29) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 30) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 31) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 32) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 33) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 34) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(18);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(9);
    else if (STATE() == 8) PUSHSTATE(13);
    else if (STATE() == 14) PUSHSTATE(26);
    else if (STATE() == 15) PUSHSTATE(27);
    else if (STATE() == 16) PUSHSTATE(28);
    else if (STATE() == 18) PUSHSTATE(29);
    else if (STATE() == 19) PUSHSTATE(30);
    else if (STATE() == 20) PUSHSTATE(31);
    else if (STATE() == 21) PUSHSTATE(32);
    else if (STATE() == 22) PUSHSTATE(33);
    else if (STATE() == 23) PUSHSTATE(34);
  }
  else { if (IS_EOF()) FAILURE(); }
}
else UNREACHABLE("Invalid parser state");
