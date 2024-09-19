#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);

int main() {
    // Declare a pointer to a function that takes two integers as arguments and returns an integer
    int (*operation)(int, int);

    // Assign the address of the add function to the pointer
    operation = add;

    // Call the function through the pointer
    printf("Result of addition: %d\n", operation(5, 3));

    // Assign the address of the subtract function to the pointer
    operation = subtract;

    // Call the function through the pointer
    printf("Result of subtraction: %d\n", operation(5, 3));

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

