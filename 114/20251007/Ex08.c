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


    // --- 4. Bit-Fields in Structs (Advanced, Implementation-Defined Aspects) ---
    // A way to explicitly define sizes of member variables in bits.
    // Useful for memory-constrained systems or specific hardware registers.
    // However, packing and ordering can be implementation-defined.
    struct PacketHeader {
        unsigned int version : 4;   // 4 bits for version
        unsigned int type : 4;      // 4 bits for type
        unsigned int flags : 8;     // 8 bits for various flags
        unsigned int length : 16;   // 16 bits for length
    };

    struct PacketHeader header;
    header.version = 4;
    header.type = 1;
    header.flags = 0xA3; // 10100011b
    header.length = 1480;
    /*
        %u doesn't know about the bit-field size
        Compiler automatically extracts and masks the bits
    */
    printf("5. Bit-fields in structs:\n");
    printf("   Packet Version: %u\n", header.version);
    printf("   Packet Type: %u\n", header.type);
    printf("   Packet Flags: 0x%02X\n", header.flags);
    printf("   Packet Length: %u\n", header.length);
    printf("   Size of PacketHeader struct: %lu bytes (can vary by compiler/packing)\n", sizeof(struct PacketHeader));
    printf("\n");


    printf("--------------------------------------------\n");
    printf("Recommendation: For predictable bitwise operations, prefer unsigned integer types,\n");
    printf("                especially fixed-width types from <stdint.h> if C99 or later is available.\n");

    return 0;
}