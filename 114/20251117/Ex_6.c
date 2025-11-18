#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Expression array (complete string array)
char expression[MAX_SIZE];

// Check if it's an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Perform calculation
double calculate(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

// Scan the array and calculate result
double scanAndCalculate() {
    double numbers[MAX_SIZE];
    char operators[MAX_SIZE];
    int numCount = 0;
    int opCount = 0;
    int i = 0;
    
    printf("\n=== Start Scanning Array ===\n");
    printf("Array content: %s\n", expression);
    
    // Step 1: Scan array, separate numbers and operators
    while (expression[i] != '=' && expression[i] != '\0') {
        // Skip spaces
        while (expression[i] == ' ') i++;
        
        if (expression[i] == '=' || expression[i] == '\0') break;
        
        // Read number
        if (isdigit(expression[i]) || expression[i] == '.') {
            double num;
            sscanf(&expression[i], "%lf", &num);
            numbers[numCount++] = num;
            printf("Scanned number: %.2f\n", num);
            
            // Skip this number
            while (isdigit(expression[i]) || expression[i] == '.') i++;
        }
        // Read operator
        else if (isOperator(expression[i])) {
            operators[opCount++] = expression[i];
            printf("Scanned operator: %c\n", expression[i]);
            i++;
        }
        else {
            i++;
        }
    }
    
    printf("\nTotal scanned: %d numbers, %d operators\n", numCount, opCount);
    
    // Step 2: Handle * and / first (higher precedence)
    printf("\n=== Phase 1: Processing * and / ===\n");
    i = 0;
    while (i < opCount) {
        if (operators[i] == '*' || operators[i] == '/') {
            double result = calculate(numbers[i], numbers[i+1], operators[i]);
            printf("Calculate: %.2f %c %.2f = %.2f\n", numbers[i], operators[i], numbers[i+1], result);
            
            // Store result back to array
            numbers[i] = result;
            
            // Remove used numbers and operators
            for (int j = i + 1; j < numCount - 1; j++) {
                numbers[j] = numbers[j + 1];
            }
            for (int j = i; j < opCount - 1; j++) {
                operators[j] = operators[j + 1];
            }
            numCount--;
            opCount--;
        } else {
            i++;
        }
    }
    
    // Step 3: Handle + and - (lower precedence)
    printf("\n=== Phase 2: Processing + and - ===\n");
    i = 0;
    while (i < opCount) {
        double result = calculate(numbers[i], numbers[i+1], operators[i]);
        printf("Calculate: %.2f %c %.2f = %.2f\n", numbers[i], operators[i], numbers[i+1], result);
        
        numbers[i] = result;
        
        for (int j = i + 1; j < numCount - 1; j++) {
            numbers[j] = numbers[j + 1];
        }
        for (int j = i; j < opCount - 1; j++) {
            operators[j] = operators[j + 1];
        }
        numCount--;
        opCount--;
    }
    
    return numbers[0];
}

int main() {
    printf("Please enter expression (separated by spaces, end with =):\n");
    printf("Example: 10.5 + 20 * 3 - 5 / 2 =\n");
    printf("Input: ");
    
    // Read entire line into array
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    
    // Check if there's an '='
    if (strchr(expression, '=') == NULL) {
        printf("Error: Expression must end with =\n");
        return 1;
    }
    
    printf("\nExpression stored in array\n");
    
    // Scan array and calculate
    double result = scanAndCalculate();
    
    printf("\n=== Final Result ===\n");
    printf("Answer: %.2f\n", result);
    
    return 0;
}