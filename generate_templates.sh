#!/bin/bash

function generate_doc()
{
    if [[ x$(find docs -name "$1_*.md") == x ]]
    then
      cat << EOF > docs/$1_.md
# Day $1

## Part One


## Part Two

EOF
    fi
}

function generate_src()
{
    if [[ x$(find include -name "$1_*.hpp") == x ]]
    then
        cat << EOF > include/$1_.hpp
#include <string>

class K$1 {
 public:
};
EOF
    fi

    if [[ x$(find src -name "$1_*.cpp") == x ]]
    then
        cat << EOF > src/$1_.cpp
#include "$1_.hpp"
EOF
    fi

    if [[ x$(find test -name "test_$1_*.cpp") == x ]]
    then
        cat << EOF > test/test_$1_.cpp
#include "$1_.hpp"
#include "gtest/gtest.h"

class T$1Test: public ::testing::Test {
    public:
};

TEST_F(T$1Test, _solvePuzzleInputPartOne) {
}

TEST_F(T$1Test, _solvePuzzleInputPartTwo) {
    
}

EOF
    fi
}

for i in $(seq 1 25)
do
    day=$(printf "%02d" $i)
    echo "Creating template for Day $day"
    generate_doc $day
    generate_src $day
done
