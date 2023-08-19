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
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(6);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(5);}
  else FAILURE();
}
else if (STATE() == 1) {
  if (false) {}
  else {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(9);
  }
}
else if (STATE() == 2) {
  if (IS_EOF()) SUCCESS();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(return)) { SHIFT(return); PUSHSTATE(11);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(10);}
  else FAILURE();
}
else if (STATE() == 3) {
  if (false) {}
  else {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(9);
  }
}
else if (STATE() == 4) {
  if (false) {}
  else {
    REDUCE(Block, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
}
else if (STATE() == 5) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(assign)) { SHIFT(assign); PUSHSTATE(12);}
  else FAILURE();
}
else if (STATE() == 6) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(15);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(14);}
  else FAILURE();
}
else if (STATE() == 7) {
  if (false) {}
  else {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(9);
  }
}
else if (STATE() == 8) {
  if (false) {}
  else {
    REDUCE(Statement, 1);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(4);
    else if (STATE() == 2) PUSHSTATE(9);
  }
}
else if (STATE() == 9) {
  if (false) {}
  else {
    REDUCE(Block, 2);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(2);
  }
}
else if (STATE() == 10) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(assign)) { SHIFT(assign); PUSHSTATE(16);}
  else FAILURE();
}
else if (STATE() == 11) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(19);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(18);}
  else FAILURE();
}
else if (STATE() == 12) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(22);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(21);}
  else FAILURE();
}
else if (STATE() == 13) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(25);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(24);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(23);}
  else FAILURE();
}
else if (STATE() == 14) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 15) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 16) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(28);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(27);}
  else FAILURE();
}
else if (STATE() == 17) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(31);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(30);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(29);}
  else FAILURE();
}
else if (STATE() == 18) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 19) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 20) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(34);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(33);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(32);}
  else FAILURE();
}
else if (STATE() == 21) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 22) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 23) {
  if (false) {}
  else {
    REDUCE(ReturnStatement, 3);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(8);
  }
}
else if (STATE() == 24) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(37);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(36);}
  else FAILURE();
}
else if (STATE() == 25) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(40);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(39);}
  else FAILURE();
}
else if (STATE() == 26) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(plus)) { SHIFT(plus); PUSHSTATE(43);}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(42);}
  else if (PEEK().type == TOKENTYPE(delim)) { SHIFT(delim); PUSHSTATE(41);}
  else FAILURE();
}
else if (STATE() == 27) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 28) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 29) {
  if (false) {}
  else {
    REDUCE(ReturnStatement, 3);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(3);
    else if (STATE() == 2) PUSHSTATE(8);
  }
}
else if (STATE() == 30) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(46);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(45);}
  else FAILURE();
}
else if (STATE() == 31) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(49);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(48);}
  else FAILURE();
}
else if (STATE() == 32) {
  if (false) {}
  else {
    REDUCE(AssignStatement, 4);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(7);
  }
}
else if (STATE() == 33) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(52);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(51);}
  else FAILURE();
}
else if (STATE() == 34) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(55);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(54);}
  else FAILURE();
}
else if (STATE() == 35) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 36) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 37) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 38) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(56);}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 39) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 40) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 41) {
  if (false) {}
  else {
    REDUCE(AssignStatement, 4);
    if (false) {}
    else if (STATE() == 0) PUSHSTATE(1);
    else if (STATE() == 2) PUSHSTATE(7);
  }
}
else if (STATE() == 42) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(59);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(58);}
  else FAILURE();
}
else if (STATE() == 43) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(62);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(61);}
  else FAILURE();
}
else if (STATE() == 44) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 45) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 46) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 47) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(63);}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 48) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 49) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 50) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 51) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 52) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 53) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(64);}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 54) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 55) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 56) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(67);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(66);}
  else FAILURE();
}
else if (STATE() == 57) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 58) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 59) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 60) {
  if (false) {}
  else if (PEEK().type == TOKENTYPE(multiply)) { SHIFT(multiply); PUSHSTATE(68);}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 61) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 62) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 63) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(71);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(70);}
  else FAILURE();
}
else if (STATE() == 64) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(74);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(73);}
  else FAILURE();
}
else if (STATE() == 65) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 66) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 67) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 68) {
  if (IS_EOF()) FAILURE();
  if (false) {}
  else if (PEEK().type == TOKENTYPE(num)) { SHIFT(num); PUSHSTATE(77);}
  else if (PEEK().type == TOKENTYPE(ident)) { SHIFT(ident); PUSHSTATE(76);}
  else FAILURE();
}
else if (STATE() == 69) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 70) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 71) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 72) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 73) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 74) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 75) {
  if (false) {}
  else {
    REDUCE(Expr, 3);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 76) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else if (STATE() == 77) {
  if (false) {}
  else {
    REDUCE(Expr, 1);
    if (false) {}
    else if (STATE() == 6) PUSHSTATE(13);
    else if (STATE() == 11) PUSHSTATE(17);
    else if (STATE() == 12) PUSHSTATE(20);
    else if (STATE() == 16) PUSHSTATE(26);
    else if (STATE() == 24) PUSHSTATE(35);
    else if (STATE() == 25) PUSHSTATE(38);
    else if (STATE() == 30) PUSHSTATE(44);
    else if (STATE() == 31) PUSHSTATE(47);
    else if (STATE() == 33) PUSHSTATE(50);
    else if (STATE() == 34) PUSHSTATE(53);
    else if (STATE() == 42) PUSHSTATE(57);
    else if (STATE() == 43) PUSHSTATE(60);
    else if (STATE() == 56) PUSHSTATE(65);
    else if (STATE() == 63) PUSHSTATE(69);
    else if (STATE() == 64) PUSHSTATE(72);
    else if (STATE() == 68) PUSHSTATE(75);
  }
}
else UNREACHABLE("Invalid parser state");
