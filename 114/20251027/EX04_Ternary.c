#include <stdio.h>

int main() {
    int age = 19;
    char* result;

    // Use the ternary operator to decide the value of 'result'
    result = (age >= 18) ? "Adult" : "Minor";

    printf("The user is a: %s\n", result); // Output: The user is a: Adult

    return 0;
}
