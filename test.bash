#!/usr/bin/env bash
# REQ: Builds with cup1. <skr 2021-01-04>
# ..............................................................................
set +B -Cefuvxo pipefail

realpath=$(realpath ${BASH_SOURCE[0]})
dirname=$(dirname "$realpath")

cd "$dirname"

pushd tests/cup2

mkdir -p bin/src
cp src/core src/_/core/core.cup bin/src/

pushd bin

mkdir -p bin
./cup build -i ./src -o ./bin/test.c

clang-format -i ./bin/test.c

sed -i '/^  l:$/d' ./bin/test.c 

gcc -o ./bin/test ./bin/test.c

./bin/test

popd

