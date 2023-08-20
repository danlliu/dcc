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
if (false) {
gotoTableExpr: 
    if (false) {}
    else if (STATE() == 8) PUSHSTATE(12);
    else if (STATE() == 10) PUSHSTATE(17);
    else if (STATE() == 11) PUSHSTATE(18);
    else if (STATE() == 14) PUSHSTATE(33);
    else if (STATE() == 20) PUSHSTATE(46);
    else if (STATE() == 23) PUSHSTATE(48);
    else if (STATE() == 24) PUSHSTATE(49);
    else if (STATE() == 25) PUSHSTATE(50);
    else if (STATE() == 27) PUSHSTATE(51);
    else if (STATE() == 28) PUSHSTATE(52);
    else if (STATE() == 29) PUSHSTATE(53);
    else if (STATE() == 30) PUSHSTATE(54);
    else if (STATE() == 31) PUSHSTATE(55);
    else if (STATE() == 32) PUSHSTATE(56);
    else if (STATE() == 36) PUSHSTATE(58);
    else if (STATE() == 37) PUSHSTATE(59);
    else if (STATE() == 38) PUSHSTATE(60);
    else if (STATE() == 39) PUSHSTATE(61);
    else if (STATE() == 40) PUSHSTATE(62);
    else if (STATE() == 41) PUSHSTATE(63);
    else if (STATE() == 42) PUSHSTATE(64);
    else if (STATE() == 43) PUSHSTATE(65);
    else if (STATE() == 45) PUSHSTATE(67);
    else if (STATE() == 76) PUSHSTATE(81);
    else if (STATE() == 79) PUSHSTATE(82);
    else if (STATE() == 80) PUSHSTATE(83);
goto endGotoTable;
gotoTableAssignStatement: 
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(1);
    else if (STATE() == 66) PUSHSTATE(69);
    else if (STATE() == 70) PUSHSTATE(69);
    else if (STATE() == 87) PUSHSTATE(69);
    else if (STATE() == 88) PUSHSTATE(69);
goto endGotoTable;
gotoTableReturnStatement: 
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(4);
    else if (STATE() == 66) PUSHSTATE(72);
    else if (STATE() == 70) PUSHSTATE(72);
    else if (STATE() == 87) PUSHSTATE(72);
    else if (STATE() == 88) PUSHSTATE(72);
goto endGotoTable;
gotoTableIfStatement: 
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(3);
    else if (STATE() == 66) PUSHSTATE(71);
    else if (STATE() == 70) PUSHSTATE(71);
    else if (STATE() == 87) PUSHSTATE(71);
    else if (STATE() == 88) PUSHSTATE(71);
goto endGotoTable;
gotoTableStatement: 
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(5);
    else if (STATE() == 2) PUSHSTATE(9);
    else if (STATE() == 66) PUSHSTATE(73);
    else if (STATE() == 70) PUSHSTATE(77);
    else if (STATE() == 87) PUSHSTATE(73);
    else if (STATE() == 88) PUSHSTATE(77);
goto endGotoTable;
gotoTableBlock: 
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
    else if (STATE() == 66) PUSHSTATE(70);
    else if (STATE() == 87) PUSHSTATE(88);
goto endGotoTable;
endGotoTable:;
}
if (false) {}
else if (STATE() == 0) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(8);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(7);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(6);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 1) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (IS_EOF()) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 2) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(8);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(7);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(6);}
  else { if (IS_EOF()) SUCCESS(); }
}
else if (STATE() == 3) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (IS_EOF()) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 4) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (IS_EOF()) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 5) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (IS_EOF()) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 6) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(assign)) { SHIFT(assign); PUSHSTATE(10);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 7) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(11);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 8) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 9) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (IS_EOF()) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 10) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 11) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 12) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(24);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(26);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(23);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 13) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 14) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 15) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(34);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 16) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 17) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(24);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(35);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(23);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 18) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) { SHIFT(rparen); PUSHSTATE(44);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(37);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(38);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(36);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 19) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 20) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 21) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(47);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 22) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 1);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 23) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 24) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 25) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 26) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (IS_EOF()) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 27) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 28) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 29) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 30) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 31) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 32) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 33) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) { SHIFT(rparen); PUSHSTATE(57);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(37);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(38);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(36);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 34) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 35) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (IS_EOF()) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 36) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 37) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 38) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 39) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 40) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 41) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 42) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 43) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 44) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(lbrace)) { SHIFT(lbrace); PUSHSTATE(66);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 45) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 46) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) { SHIFT(rparen); PUSHSTATE(68);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(37);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(38);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(36);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 47) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 2);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 48) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 49) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 50) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 51) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 52) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 53) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 54) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 55) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 56) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 57) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(delim)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 58) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 59) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 60) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 61) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 62) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 63) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 64) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 65) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 66) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(76);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(75);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(74);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 67) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 68) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(plus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(minus)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(lshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(multiply)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(divide)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(rshift)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitxor)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else if (PEEK().type == TOKENTYPE(bitand)) {
    REDUCE(Expr, 3);
    goto gotoTableExpr;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 69) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 70) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(76);}
  else if (PEEK().type == TOKENTYPE(rbrace)) { SHIFT(rbrace); PUSHSTATE(78);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(75);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(74);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 71) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 72) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Statement, 1);
    goto gotoTableStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 73) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 1);
    goto gotoTableBlock;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 74) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(assign)) { SHIFT(assign); PUSHSTATE(79);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 75) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(80);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 76) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 77) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(Block, 2);
    goto gotoTableBlock;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 78) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (IS_EOF()) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 79) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(16);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(14);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(13);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 80) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(21);}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(lparen)) { SHIFT(lparen); PUSHSTATE(20);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(19);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 81) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(24);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(84);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(23);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 82) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(29);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(24);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(27);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(85);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(32);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(23);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 83) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(rparen)) { SHIFT(rparen); PUSHSTATE(86);}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(minus)) { SHIFT(minus); PUSHSTATE(41);}
  else if (PEEK().type == TOKENTYPE(lshift)) { SHIFT(lshift); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(bitor)) { SHIFT(bitor); PUSHSTATE(37);}
  else if (PEEK().type == TOKENTYPE(divide)) { SHIFT(divide); PUSHSTATE(39);}
  else if (PEEK().type == TOKENTYPE(rshift)) { SHIFT(rshift); PUSHSTATE(45);}
  else if (PEEK().type == TOKENTYPE(bitxor)) { SHIFT(bitxor); PUSHSTATE(38);}
  else if (PEEK().type == TOKENTYPE(bitand)) { SHIFT(bitand); PUSHSTATE(36);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 84) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(ReturnStatement, 3);
    goto gotoTableReturnStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 85) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(AssignStatement, 4);
    goto gotoTableAssignStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 86) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(lbrace)) { SHIFT(lbrace); PUSHSTATE(87);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 87) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(76);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(75);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(74);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 88) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(76);}
  else if (PEEK().type == TOKENTYPE(rbrace)) { SHIFT(rbrace); PUSHSTATE(89);}
  else if (PEEK().type == TOKENTYPE(if)) { SHIFT(if); PUSHSTATE(75);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(74);}
  else { if (IS_EOF()) FAILURE(); }
}
else if (STATE() == 89) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (PEEK().type == TOKENTYPE(rbrace)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (PEEK().type == TOKENTYPE(if)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else if (PEEK().type == TOKENTYPE(ident)) {
    REDUCE(IfStatement, 7);
    goto gotoTableIfStatement;
  }
  else { if (IS_EOF()) FAILURE(); }
}
else UNREACHABLE("Invalid parser state");
