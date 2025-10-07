#include <stdio.h>   // Required for printf()
#include <limits.h>  // Required for integer type limits (CHAR_MIN, INT_MAX, etc.)
#include <float.h>   // Required for floating-point type limits (FLT_MIN, DBL_MAX, etc.)
#include <stdbool.h> // Required for bool type (if demonstrating its size)

int main() {
    printf("--- C Data Types: Size, Minimum, and Maximum Values ---\n\n");

    // Print table header
    // %-20s: left-justified string, 20 chars wide
    // %-6s: left-justified string, 6 chars wide
    // %-30s: left-justified string, 30 chars wide
    printf("%-20s | %-6s | %-30s | %-30s\n", "Data Type", "Size", "Minimum Value", "Maximum Value");
    printf("---------------------|--------|--------------------------------|--------------------------------\n");

    // --- Character Type ---
    // Note: char can be signed or unsigned by default. We print its actual limits.
    printf("%-20s | %-6lu | %-30d | %-30d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);

    // --- Integer Types ---
    printf("%-20s | %-6lu | %-30d | %-30d\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    // Use %d for int min/max
    printf("%-20s | %-6lu | %-30d | %-30d\n", "int", sizeof(int), INT_MIN, INT_MAX);
    // Use %ld for long min/max
    printf("%-20s | %-6lu | %-30ld | %-30ld\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
    // Use %lld for long long min/max
    printf("%-20s | %-6lu | %-30lld | %-30lld\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);

    // --- Floating-Point Types ---
    // Use %g for float/double for compact representation (chooses %f or %e)
    // For long double, use %Lg
    printf("%-20s | %-6lu | %-30g | %-30g\n", "float", sizeof(float), FLT_MIN, FLT_MAX);
    printf("%-20s | %-6lu | %-30g | %-30g\n", "double", sizeof(double), DBL_MIN, DBL_MAX);
    printf("%-20s | %-6lu | %-30Lg | %-30Lg\n", "long double", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // --- Pointer Type ---
    // Pointers don't have numeric min/max; they represent addresses.
    printf("%-20s | %-6lu | %-30s | %-30s\n", "void * (ptr)", sizeof(void *), "N/A (memory address)", "N/A (memory address)");

    // --- Optional: Boolean Type (requires C99 and <stdbool.h>) ---
    // Uncomment if you want to include _Bool (bool)
    // printf("%-20s | %-6lu | %-30d | %-30d\n", "bool", sizeof(bool), false, true);


    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\nNote: Sizes and ranges can vary based on compiler and system architecture.\n");
    printf("      (Min/Max values shown are typically for signed types where applicable, and positive for float types).\n");

    return 0; // Indicate successful program execution
}