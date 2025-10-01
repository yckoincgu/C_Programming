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
    printf("  Size: %lu byte(s)\n", sizeof(short));
    printf("  Min Value: %d\n", SHRT_MIN);
    printf("  Max Value: %d\n\n", SHRT_MAX);

    printf("Type: unsigned short int (or unsigned short)\n");
    printf("  Size: %lu byte(s)\n", sizeof(unsigned short));
    printf("  Min Value: %d\n", 0);
    printf("  Max Value: %d\n\n", USHRT_MAX);

    printf("Type: int\n");
    printf("  Size: %lu byte(s)\n", sizeof(int));
    printf("  Min Value: %d\n", INT_MIN);
    printf("  Max Value: %d\n\n", INT_MAX);

    printf("Type: unsigned int (or unsigned)\n");
    printf("  Size: %lu byte(s)\n", sizeof(unsigned int));
    printf("  Min Value: %u\n", 0); // Use %u for unsigned int
    printf("  Max Value: %u\n\n", UINT_MAX);

    printf("Type: long int (or long)\n");
    printf("  Size: %lu byte(s)\n", sizeof(long));
    printf("  Min Value: %ld\n", LONG_MIN); // Use %ld for long
    printf("  Max Value: %ld\n\n", LONG_MAX);

    printf("Type: unsigned long int (or unsigned long)\n");
    printf("  Size: %lu byte(s)\n", sizeof(unsigned long));
    printf("  Min Value: %lu\n", 0UL); // Use %lu for unsigned long
    printf("  Max Value: %lu\n\n", ULONG_MAX);

    printf("Type: long long int (or long long)\n");
    printf("  Size: %lu byte(s)\n", sizeof(long long));
    printf("  Min Value: %lld\n", LLONG_MIN); // Use %lld for long long
    printf("  Max Value: %lld\n\n", LLONG_MAX);

    printf("Type: unsigned long long int (or unsigned long long)\n");
    printf("  Size: %lu byte(s)\n", sizeof(unsigned long long));
    printf("  Min Value: %llu\n", 0ULL); // Use %llu for unsigned long long
    printf("  Max Value: %llu\n\n", ULLONG_MAX);

    // --- Floating-Point Types ---
    printf("--- Floating-Point Types ---\n");
    printf("Type: float\n");
    printf("  Size: %lu byte(s)\n", sizeof(float));
    printf("  Min Value: %e\n", FLT_MIN); // %e for scientific notation
    printf("  Max Value: %e\n\n", FLT_MAX);

    printf("Type: double\n");
    printf("  Size: %lu byte(s)\n", sizeof(double));
    printf("  Min Value: %e\n", DBL_MIN);
    printf("  Max Value: %e\n\n", DBL_MAX);

    printf("Type: long double\n");
    printf("  Size: %lu byte(s)\n", sizeof(long double));
    printf("  Min Value: %Le\n", LDBL_MIN); // %Le for long double scientific notation
    printf("  Max Value: %Le\n\n", LDBL_MAX);

    // --- Boolean Type (C99 and later) ---
    printf("--- Boolean Type ---\n");
    printf("Type: bool\n");
    printf("  Size: %lu byte(s)\n", sizeof(bool));
    // For bool, min is effectively 0 (false) and max is 1 (true)
    printf("  Min Value: %d (false)\n", false);
    printf("  Max Value: %d (true)\n\n", true);


    // --- Pointer Type ---
    printf("--- Pointer Type ---\n");
    printf("Type: void *\n");
    printf("  Size: %lu byte(s)\n", sizeof(void *));
    // Pointers don't have typical min/max values like integers;
    // they represent memory addresses.
    printf("  (Min/Max values are memory addresses, system-dependent)\n\n");


    printf("---------------------------------------------------\n");

    return 0; // Indicate successful program execution
}