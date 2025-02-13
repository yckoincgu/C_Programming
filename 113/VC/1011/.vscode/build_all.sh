#!/bin/bash

CFLAGS="-Wall -Wextra -g3 -lglfw -lGL -lm"

# Compile all .c files in the current directory
for file in *.c; do
    output_name="${file%.c}" # Remove the .c extension
    gcc $CFLAGS "$file" -o "$output_name"
    if [ $? -eq 0 ]; then
        echo "Compiled: $file -> $output_name"
    else
        echo "Error compiling: $file"
        exit 1 # Exit with error code to indicate failure
    fi
done

echo "Build complete!"