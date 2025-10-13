#include <stdio.h>
#include <limits.h> // For CHAR_BIT (number of bits in a char)
#include <stdint.h> // For fixed-width integer types (C99 standard)

/*
    * This program demonstrates the use of various C data types for bitwise operations.
    * It highlights the advantages and disadvantages of each type in the context of bit manipulation.
    * The examples include standard unsigned types, fixed-width types, signed types, and bit-fields.
    * 
    * Note: This code is written in C and adheres to the C17 standard.
    * Bit Position:  7 6 5 4 3 2 1 0
    * Binary Value:  0 0 0 0 0 1 0 1
*/


// Function to print the binary representation of an unsigned char
void print_byte_binary(unsigned char byte) {
    int i;
    for (i = CHAR_BIT - 1; i >= 0; i--) { // CHAR_BIT is typically 8
        printf("%d", (byte >> i) & 1);    // >> bitwise right shift operator
                                          // i: The number of positions you want to shift the bits to the right.
    }
}

int main() {
    printf("--- C Data Types for Bitwise Operations ---\n\n");

    // --- 1. Standard Unsigned Integer Types (Recommended for general use) ---
    // These are excellent for bit manipulation due to well-defined behavior.

    // unsigned char (8 bits typically)
    unsigned char sensor_flags = 0x05; // 00000101 in binary

    // Toggle a bit (e.g., toggle 1st bit, which is 2^1 = 2, so 0x02)
    sensor_flags ^= (1 << 1); 
    /*
    Visual representation: 1 << 1
        0 0 0 0 0 0 0 1   ← Original (1)
        ⇦ ⇦ ⇦ ⇦ ⇦ ⇦ ⇦ ⇦   ← All bits move left by 1
        0 0 0 0 0 0 1 0   ← Result (2)

    Bitwise XOR operation toggles the 1st bit
        0 0 0 0 0 1 0 1   ← Original (5)
        0 0 0 0 0 0 1 0   ← Mask (2)
        -----------------
        0 0 0 0 0 1 1 1   ← Result (7)  

    */
        
    printf("   After toggling 1st bit: 0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");
    printf("\n");


    return 0;
}