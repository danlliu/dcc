# dcc

## Language Specification

Start simple:

```
Terminals:
num = (\-?[0-9]+)     : numeric constant
ident = [A-Za-z_]+    : identifier name
delim = ;             : command delimiter
return = return       : return token
assign = [=]          : operators

Program =
  Statement                                 (r0)
  Program Statement   : multiple statements (r1)

Statment =
  ident = Expr ;      : assignment          (r2)
  return Expr ;       : return              (r3)

Expr =
  num                                       (r4)
  ident                                     (r5)
```

LR Parser:

```
State 0:
S -> # Program (eof)
+ Program -> # Statement
+ Program -> # Program Statement
+ Statement -> # ident assign Expr ;
+ Statement -> # return Expr ;

Symbols after #: [ Program, Statement, ident, return ]

State 1: 0, Program
S -> Program # (eof)
Program -> Program # Statement
Closure covered by 0

State 2: 0, Statement
Program -> Statement #

State 3: 0, ident
Statement -> ident # assign Expr ;

State 4: 0, return
Statement -> return # Expr ;
+ Expr -> # num
+ Expr -> # ident

State 5: 1, Statement
Program -> Program Statement #
Closure covered by 1

State 6: 3, assign
Statement -> ident assign # Expr ;
Closure covered by 4

State 7: 4, Expr
Statement -> return Expr # ;

State 8: 4, num
Expr -> num #

State 9: 4, ident
Expr -> ident #

State 10: 6, Expr
Statement -> ident assign Expr # ;

State 11: 7, ;
Statement -> return Expr ; #

State 12: 10, ;
Statement -> ident assign Expr ; #

----------------

State 0:
  Program => 1
  Statement => 2
  ident => 3
  return => 4

State 1:
  

----------------

LHS GOTO TABLE

Program:
  - from 0: goto 2
  - from 2: goto 2
```