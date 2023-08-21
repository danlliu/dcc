#!/bin/sh

which as
if [ "$?" -ne "0" ]; then
  echo "as not detected"
  exit 1
fi

mkdir tmp
./dcc $@ > tmp/dlang.s
as -arch arm64 -o tmp/dlang.out tmp/dlang.s
make runtime/main.o
g++ runtime/main.o tmp/dlang.out -o a.out
