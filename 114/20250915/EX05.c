#include <stdio.h>   // Required for printf()
#include <limits.h>  // Required for CHAR_MIN, INT_MAX, etc.
#include <float.h>   // Required for FLT_MIN, DBL_MAX, etc.
#include <stdbool.h> // Required for bool type

int main() {
    printf("--- C Data Types: Size, Min, and Max Values ---\n\n");

    // --- Character Types ---
    printf("--- Character Types ---\n");
    printf("Type: char\n");
    printf("  Size: %lu byte(s)\n", sizeof(char));
    printf("  Min Value: %d\n", CHAR_MIN);
    printf("  Max Value: %d\n\n", CHAR_MAX);

    printf("Type: signed char\n");
    printf("  Size: %lu byte(s)\n", sizeof(signed char));
    printf("  Min Value: %d\n", SCHAR_MIN);
    printf("  Max Value: %d\n\n", SCHAR_MAX);

    printf("Type: unsigned char\n");
    printf("  Size: %lu byte(s)\n", sizeof(unsigned char));
    printf("  Min Value: %d\n", 0); // Unsigned types always start from 0
    printf("  Max Value: %d\n\n", UCHAR_MAX);

    // --- Integer Types ---
    printf("--- Integer Types ---\n");
    printf("Type: short int (or short)\n");
    printf("  Size: %lu