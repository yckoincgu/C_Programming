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
    // unsigned int (often 32 bits)
    unsigned int control_register = 0xAAAA5555;
    printf("   Control Register: 0x%08X\n", control_register);
    /* Check if a specific bit is set (e.g., 16th bit)
       Right shift by 16 positions moves the upper 16 bits to the lower 16 positions:

        Before shift:
        [1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0] [0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1]
        Upper 16 bits                      Lower 16 bits

        After >> 16:
        [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0] [1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0]
        New upper 16 bits (zeros)          Original upper 16 bits now in lower position
    */ 
    if ((control_register >> 16) & 1) {
        printf("   Bit 16 is set.\n");
    } else {
        printf("   Bit 16 is not set.\n");
    }
    printf("\n");

    return 0;
}