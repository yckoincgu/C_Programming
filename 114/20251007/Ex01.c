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
    printf("1. unsigned char:\n");
    printf("   Initial sensor_flags: 0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");

    // Set a bit (e.g., set 3rd bit, which is 2^2 = 4, so 0x04)
    sensor_flags |= (1 << 2); // Mask (1 << 2): 00000100
                              // Bitwise OR operation sets the 2nd bit
                              // 00000101
                              // Result: 00000101 (0x0D)
    printf("   After setting 3rd bit:  0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");

    // Clear a bit (e.g., clear 0th bit, which is 2^0 = 1, so ~0x01)
    sensor_flags &= ~(1 << 0); // Result: 00001100 (0x0C)
    printf("   After clearing 0th bit: 0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");

    // Toggle a bit (e.g., toggle 1st bit, which is 2^1 = 2, so 0x02)
    sensor_flags ^= (1 << 1); // Result: 00001000 (0x08)
    printf("   After toggling 1st bit: 0x%02X (binary: ", sensor_flags);
    print_byte_binary(sensor_flags);
    printf(")\n");
    printf("\n");

    // unsigned int (often 32 bits)
    unsigned int control_register = 0xAAAA5555;
    printf("2. unsigned int:\n");
    printf("   Control Register: 0x%08X\n", control_register);
    // Check if a specific bit is set (e.g., 16th bit)
    if ((control_register >> 16) & 1) {
        printf("   Bit 16 is set.\n");
    } else {
        printf("   Bit 16 is not set.\n");
    }
    printf("\n");

    // --- 2. Fixed-Width Unsigned Integer Types (C99 and later, RECOMMENDED for precision) ---
    // Use these when you need to guarantee a specific number of bits (e.g., for hardware or protocols).
    // Requires #include <stdint.h>

    uint8_t crc_byte = 0xCD; // Guaranteed 8 bits
    printf("3. Fixed-width types (from <stdint.h>):\n");
    printf("   CRC Byte (uint8_t): 0x%02X\n", crc_byte);

    uint16_t timer_value = 0x1234; // Guaranteed 16 bits
    printf("   Timer Value (uint16_t): 0x%04X\n", timer_value);

    uint32_t network_mask = 0xFFFFFF00; // Guaranteed 32 bits
    printf("   Network Mask (uint32_t): 0x%08X\n", network_mask);

    uint64_t large_id = 0xFEDCBA9876543210ULL; // Guaranteed 64 bits (ULL suffix for unsigned long long)
    printf("   Large ID (uint64_t): 0x%016llX\n", large_id);
    printf("\n");

    // --- 3. Standard Signed Integer Types (Use with CAUTION for bitwise ops) ---
    // Bitwise operations on signed types, especially right shift of negative numbers,
    // can have implementation-defined behavior. Avoid for precise bit manipulation.
    signed char signed_data = -5; // Example negative value
    printf("4. Signed char (use with caution for bitwise ops):\n");
    printf("   Signed data: %d (0x%02X)\n", signed_data, (unsigned char)signed_data);
    signed_data >>= 2; // Right shift on signed negative is implementation-defined
    printf("   After right shift by 2: %d (0x%02X) (Behavior varies by compiler/system!)\n", signed_data, (unsigned char)signed_data);
    printf("\n");

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