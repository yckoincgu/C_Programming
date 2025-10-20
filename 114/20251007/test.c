#include <stdio.h>
int main() {
    int num;          // The number to calculate the factorial of
    long long factorial = 1; 
    int i;            // Loop counter
    printf("Enter a positive integer (max 12 for standard int size): ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Return error code
    }

    if (num == 0) factorial = 1;
    else for (i = num; i >= 1; i--) 
            factorial = factorial * i; 
    printf("The factorial of %d is: %lld\n", num, factorial);

    return 0;
}