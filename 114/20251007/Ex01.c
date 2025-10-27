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
/*
i value	Operation: (byte >> i) & 1	Binary Representation	Result
i = 7	(5 >> 7) & 1	00000101 >> 7 = 00000000 → 00000000 & 00000001	0
i = 6	(5 >> 6) & 1	00000101 >> 6 = 00000000 → 00000000 & 00000001	0
i = 5	(5 >> 5) & 1	00000101 >> 5 = 00000000 → 00000000 & 00000001	0
i = 4	(5 >> 4) & 1	00000101 >> 4 = 00000000 → 00000000 & 00000001	0
i = 3	(5 >> 3) & 1	00000101 >> 3 = 00000000 → 00000000 & 00000001	0
i = 2	(5 >> 2) & 1	00000101 >> 2 = 00000001 → 00000001 & 00000001	1
i = 1	(5 >> 1) & 1	00000101 >> 1 = 00000010 → 00000010 & 00000001	0
i = 0	(5 >> 0) & 1	00000101 >> 0 = 00000101 → 00000101 & 00000001	1
*/
void print_byte_binary(unsigned char byte) {
    int i;
    for (i = CHAR_BIT - 1; i >= 0; i--) { // CHAR_BIT is typically 8
        printf("%d", (byte >> i) & 1);    // >> bitwise right shift operator
                                          // i: The number of positions you want to shift the bits to the right.
    }
}

int main() {
    printf("--- C Data Types for Bitwise Operations ---\n\n");
    // unsigned char (8 bits typically)
    unsigned char sensor_flags = 0x05; // 00000101 in binary
    printf("1. unsigned char:\n");
    // print an unsigned hexadecimal integer by X format specifier
     printf("   Initial sensor_flags: 0x%02X (binary: ", sensor_flags);
    printf("   Initial sensor_flags: 0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");
    return 0;
}