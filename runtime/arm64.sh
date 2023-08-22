#!/bin/sh

which as > /dev/null
if [ "$?" -ne "0" ]; then
  echo "as not detected"
  exit 1
fi

OFILE='a.out'
PARAMS=''

while [[ $# -ne 0 ]]; do
  if [[ "$1" == '-o' ]]; then
    shift
    OFILE=$1
  else
    PARAMS="$PARAMS $1"
  fi
  shift
done

mkdir tmp
./dcc $PARAMS > tmp/dlang.s
as -arch arm64 -o tmp/dlang.out tmp/dlang.s
make runtime/main.o
g++ runtime/main.o tmp/dlang.out -o $OFILE
