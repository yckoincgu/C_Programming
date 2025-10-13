#include <stdio.h>

/**
 * Main function: Prompts the user for a number (up to 12 for int type),
 * calculates its factorial using a for loop, and prints the result.
 */
int main() {
    int num;          // The number to calculate the factorial of
    long long factorial = 1; // Use long long to avoid overflow for larger numbers, initialized to 1
    int i;            // Loop counter

    // Get input from the user
    printf("Enter a positive integer (max 12 for standard int size): ");
    // Note: The factorial grows very fast. A standard 'int' can only handle up to 12!
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Return error code
    }

    // Check for the base case (Factorial of 0 is 1)
    if (num == 0) {
        factorial = 1;
    } else {
        // Factorial calculation loop: i goes from the input number down to 1
        for (i = num; i >= 1; i--) {
            factorial = factorial * i; // Multiply the running product by the current number
            // This is equivalent to: factorial *= i;
        }
    }

    // Print the final result
    printf("The factorial of %d is: %lld\n", num, factorial);

    return 0;
}