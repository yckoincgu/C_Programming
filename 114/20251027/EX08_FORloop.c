#include <stdio.h>

int main() {
    int i;
    
    printf("=== BASIC FOR LOOP EXAMPLES ===\n\n");
    
    // Example 1: Simple counting from 1 to 10
    printf("1. Counting from 1 to 10:\n");
    for(i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // Example 2: Counting backwards
    printf("2. Counting backwards from 10 to 1:\n");
    for(i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // Example 3: Even numbers only
    printf("3. Even numbers between 1 and 20:\n");
    for(i = 2; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // Example 4: Multiplication table
    int number = 5;
    printf("4. Multiplication table of %d:\n", number);
    for(i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }
    printf("\n");
    
    // Example 5: Sum of numbers
    printf("5. Sum of numbers from 1 to 100:\n");
    int sum = 0;
    for(i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Sum = %d\n\n", sum);
    
    // Example 6: Nested FOR loop (pattern printing)
    printf("6. Pattern using nested FOR loops:\n");
    int rows = 5, j;
    for(i = 1; i <= rows; i++) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    
    // Example 7: Array traversal
    printf("7. Array traversal using FOR loop:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array elements: ");
    for(i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    // Example 8: FOR loop with multiple variables
    printf("8. FOR loop with multiple variables:\n");
    for(i = 0, j = 10; i <= 10; i++, j--) {
        printf("i=%d, j=%d\n", i, j);
    }
    printf("\n");
    
    // Example 9: FOR loop with break statement
    printf("9. FOR loop with break (stops at 5):\n");
    for(i = 1; i <= 10; i++) {
        if(i == 6) {
            break;
        }
        printf("%d ", i);
    }
    printf("\n\n");
    
    // Example 10: FOR loop with continue statement
    printf("10. FOR loop with continue (skips 5):\n");
    for(i = 1; i <= 10; i++) {
        if(i == 5) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}