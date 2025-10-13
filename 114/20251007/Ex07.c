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

    // --- 3. Standard Signed Integer Types (Use with CAUTION for bitwise ops) ---
    // Bitwise operations on signed types, especially right shift of negative numbers,
    // can have implementation-defined behavior. Avoid for precise bit manipulation.
    signed char signed_data = -5; // Example negative value
    printf("4. Signed char (use with caution for bitwise ops):\n");
    printf("   Signed data: %d (0x%02X)\n", signed_data, (unsigned char)signed_data);
    signed_data >>= 2; 
    /*
    Original: [1][1][1][1][1][0][1][1]
          │ │ │ │ │ │ │ │
          │ │ │ │ │ │ │ └── Bit 0: shifted out (lost)
          │ │ │ │ │ │ └── Bit 1: shifted out (lost)
          │ │ │ │ │ └── Bit 2 → New Bit 0
          │ │ │ │ └── Bit 3 → New Bit 1
          │ │ │ └── Bit 4 → New Bit 2
          │ │ └── Bit 5 → New Bit 3
          │ └── Bit 6 → New Bit 4
          └── Sign bit (1) → New Bits 5, 6, 7

    Result:   [1][1][1][1][1][1][1][0]

    Convert back to decimal:
    Binary: 11111110
    One's complement: 00000001
    Add 1: 00000010 = 2
    Therefore: 11111110 = -2

    */
    printf("   After right shift by 2: %d (0x%02X) (Behavior varies by compiler/system!)\n", signed_data, (unsigned char)signed_data);
    printf("\n");

    return 0;
}