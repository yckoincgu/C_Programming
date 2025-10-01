#include <stdio.h>   // Required for printf()
#include <limits.h>  // Required for integer type limits
#include <float.h>   // Required for floating-point type limits
#include <stdbool.h> // Required for bool type

int main() {
    printf("--- C Data Types Information Table ---\n\n");

    // Print table header
    printf("%-20s | %-6s | %-30s | %-30s\n", "Data Type", "Size", "Minimum Value", "Maximum Value");
    printf("---------------------|--------|--------------------------------|--------------------------------\n");

    // --- Character Types ---
    printf("%-20s | %-6lu | %-30d | %-30d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("%-20s | %-6lu | %-30d | %-30d\n", "signed char", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("%-20s | %-6lu | %-30d | %-30d\n", "unsigned char", sizeof(unsigned char), 0, UCHAR_MAX);

    // --- Integer Types ---
    printf("%-20s | %-6lu | %-30d | %-30d\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("%-20s | %-6lu | %-30d | %-30d\n", "unsigned short", sizeof(unsigned short), 0, USHRT_MAX);
    printf("%-20s | %-6lu | %-30d | %-30d\n", "int", sizeof(int), INT_MIN, INT_MAX);
    printf("%-20s | %-6lu | %-30u | %-30u\n", "unsigned int", sizeof(unsigned int), 0u, UINT_MAX); // Note 0u
    printf("%-20s | %-6lu | %-30ld | %-30ld\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
    printf("%-20s | %-6lu | %-30lu | %-30lu\n", "unsigned long", sizeof(unsigned long), 0ul, ULONG_MAX); // Note 0ul
    printf("%-20s | %-6lu | %-30lld | %-30lld\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("%-20s | %-6lu | %-30llu | %-30llu\n", "unsigned long long", sizeof(unsigned long long), 0ull, ULLONG_MAX); // Note 0ull

    // --- Floating-Point Types ---
    // Using %g for floats/doubles to get a compact representation (either %f or %e)
    // Adjust precision as needed, e.g., %.7g
    printf("%-20s | %-6lu | %-30g | %-30g\n", "float", sizeof(float), FLT_MIN, FLT_MAX);
    printf("%-20s | %-6lu | %-30g | %-30g\n", "double", sizeof(double), DBL_MIN, DBL_MAX);
    // For long double, use %Lg
    printf("%-20s | %-6lu | %-30Lg | %-30Lg\n", "long double", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // --- Boolean Type ---
    printf("%-20s | %-6lu | %-30d | %-30d\n", "bool", sizeof(bool), false, true);

    // --- Pointer Type ---
    printf("%-20s | %-6lu | %-30s | %-30s\n", "void * (ptr)", sizeof(void *), "N/A (memory address)", "N/A (memory address)");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\nNote: Sizes and ranges can vary based on compiler and system architecture.\n");

    return 0;
}