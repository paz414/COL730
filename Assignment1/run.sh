#!/bin/bash

# Compile your C++ program
g++ -std=c++11 -fopenmp main.cpp par_merge_sort.cpp seq_merge_sort.cpp par_bin_search.cpp seq_bin_search.cpp functions.h -o a

# Run your program
./a

# If you need to pass any arguments, you can do it like this:
# ./assignment1 arg1 arg2
