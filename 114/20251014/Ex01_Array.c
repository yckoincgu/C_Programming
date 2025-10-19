#include <stdio.h>

int main() {
    // (1) Declare an array with 5 integers
    // The array 'numbers' can hold 5 integer values.
    int numbers[5]; 
    int i; // Loop counter

    // (2) Let users to input these 5 integers
    printf("--- Input Section ---\n");
    printf("Please enter 5 integers:\n");

    for (i = 0; i < 5; i++) {
        printf("Enter integer #%d: ", i + 1);
        
        // Use the address-of operator (&) to store the input 
        // directly into the i-th element of the array.
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please run the program again.\n");
            return 1; // Exit with error
        }
    }

    // (3) Output these 5 integers
    printf("\n--- Output Section ---\n");
    printf("The 5 integers you entered are:\n");

    for (i = 0; i < 5; i++) {
        // Access the value at the i-th element of the array.
        printf("Integer #%d: %d\n", i + 1, numbers[i]);
    }

    return 0;
}