#!/bin/bash

# Compiler flags
CFLAGS="-Wall -Wextra -g3 -lglfw -lGL -lm"

# Output executable name
TARGET="EX1018"

# Compile all C files in the current directory
# gcc $CFLAGS *.c -o $TARGET
gcc EX1018_1.c lib_test.c -o $TARGET
# Optional: Clean up object files (if you want)
# rm *.o