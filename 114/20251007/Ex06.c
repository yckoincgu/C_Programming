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

    uint8_t crc_byte = 0xCD; // Guaranteed 8 bits
/*
    A CRC Byte is an 8-bit error-detection code 
    calculated from data using polynomial division. 
    It's widely used in communication protocols, storage systems, 
    and networking to ensure data integrity during transmission or storage.
*/
    printf("   CRC Byte (uint8_t): 0x%02X\n", crc_byte);

    uint16_t timer_value = 0x1234; // Guaranteed 16 bits
    printf("   Timer Value (uint16_t): 0x%04X\n", timer_value);

    uint32_t network_mask = 0xFFFFFF00; // Guaranteed 32 bits
    printf("   Network Mask (uint32_t): 0x%08X\n", network_mask);

    uint64_t large_id = 0xFEDCBA9876543210ULL; // Guaranteed 64 bits (ULL suffix for unsigned long long)
    printf("   Large ID (uint64_t): 0x%016llX\n", large_id);
    // ll format specifier for unsigned long long
    // at least 16 characters wide
    printf("\n");


    return 0;
}