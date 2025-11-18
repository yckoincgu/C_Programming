#include <stdio.h>

int main() {
    int number, a, b, c, d, e;
    int calculated;
    
    printf("Enter a 5-digit integer: ");
    scanf("%d", &number);
    
    a = number / 10000;           // First digit
    b = (number / 1000) % 10;     // Second digit
    c = (number / 100) % 10;      // Third digit
    d = (number / 10) % 10;       // Fourth digit
    e = number % 10;              // Fifth digit
    
    // Calculate using the formula: 1*1*1 + 5*5*5 + 3*3*3
    // Pattern: a*a*a + b*b*b + c*c*c + d*d*d + e*e*e
    calculated = a*a*a + b*b*b + c*c*c + d*d*d + e*e*e;
    
    printf("Digits: a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);
    printf("Calculated value: %d\n", calculated);
    
    // Check if it matches the original number
    if (calculated == number) {
        printf("Result: abcde\n");
    } else {
        printf("Result: not abcde\n");
    }
    
    return 0;
}