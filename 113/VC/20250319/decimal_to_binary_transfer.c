#include <stdio.h>
#include <stdlib.h>

char* transfer(int x) {
    // Handle special case for 0
    if (x == 0) {
        char* result = malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    // Calculate the number of bits needed
    int temp = x;
    int num_bits = 0;
    while (temp > 0) {
        num_bits++;
        temp /= 2;
    }
    
    // Allocate memory for the binary string (including null terminator)
    char* binary = malloc((num_bits + 1) * sizeof(char));
    
    // Convert decimal to binary
    int index = num_bits - 1;
    temp = x;
    while (temp > 0) {
        binary[index] = (temp % 2) + '0'; // Convert digit to character
        temp /= 2;
        index--;
    }
    binary[num_bits] = '\0'; // Null terminate the string
    
    return binary;
}