#include <stdio.h> // Required for printf() function

int main() {
    printf("--- C Data Types Sizes ---\n\n");

    // Integer types
    printf("Size of char:        %lu byte(s)\n", sizeof(char));
    printf("Size of short:       %lu byte(s)\n", sizeof(short));
    printf("Size of int:         %lu byte(s)\n", sizeof(int));
    printf("Size of long:        %lu byte(s)\n", sizeof(long));
    printf("Size of long long:   %lu byte(s)\n\n", sizeof(long long));

    // Floating-point types
    printf("Size of float:       %lu byte(s)\n", sizeof(float));
    printf("Size of double:      %lu byte(s)\n", sizeof(double));
    printf("Size of long double: %lu byte(s)\n\n", sizeof(long double));

    // Pointer type (size of a memory address)
    // The size of a pointer is typically the same regardless of what it points to.
    printf("Size of a pointer:   %lu byte(s)\n\n", sizeof(void *));

    // Boolean type (from C99 standard, requires <stdbool.h>)
    // For simplicity, we'll demonstrate its size here,
    // though typically represented by an int or char under the hood.
    // If you uncomment the line below, you'd need to add #include <stdbool.h>
    // printf("Size of _Bool:       %lu byte(s)\n", sizeof(_Bool));

    printf("--------------------------\n");

    return 0; // Indicate successful program execution
}