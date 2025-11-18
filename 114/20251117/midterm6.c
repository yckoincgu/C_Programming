#include <stdio.h>
#include <ctype.h>

#define MAX_ITEMS 20  

int main() {
    char expr[MAX_ITEMS];  
    int i = 0;
    double result = 0, temp = 0;
    char op = '+';      
    double num;
    
    printf("Enter arithmetic expression (end with '='):\n");
   
    while (i < MAX_ITEMS) {
        char ch;
        scanf(" %c", &ch);

        expr[i++] = ch;
        if (ch == '=') break;
    }

    printf("\nExpression stored in array: ");
    for (int j = 0; j < i; j++) printf("%c", expr[j]);
    printf("\n");

    for (int j = 0; j < i; j++) {
        char ch = expr[j];
        if (isdigit(ch) || ch == '.') {
            ungetc(ch, stdin);       // put digit back to read double
            scanf("%lf", &num);     
            if (op == '+') result += num;
            else if (op == '-') result -= num;
            else if (op == '*') result *= num;
            else if (op == '/') result /= num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op = ch;                
        } else if (ch == '=') {
            break;                 
        }
    }

    printf("Result: %.2lf\n", result);

    return 0;
}
// Start
//   |
//   v
// Define:
//   MAX_ITEMS
//   expr[MAX_ITEMS]       // array to store characters (numbers and operators)
//   result = 0, op = '+'
//   i = 0
//   |
//   v
// Prompt user: "Enter arithmetic expression ending with '='"
//   |
//   v
// Read character ch from input
//   |
//   +--> Is ch '=' or i == MAX_ITEMS? ----> Yes ----> Stop input reading
//   |                                       |
//   |                                       v
//   |                                   expr[i++] = ch
//   |                                       |
//   |<--------------------------------------No
//   |
// Repeat reading next character
// 
// After input is done:
//   |
//   v
// Print stored expression in expr[0..i-1]
//   |
//   v
// Initialize j = 0
//   |
//   v
// Loop: for each character expr[j]
//   |
//   +--> If expr[j] is digit or '.'
//   |         |
//   |         v
//   |      Put expr[j] back into stdin (ungetc)
//   |         |
//   |         v
//   |      Read full number using scanf("%lf", &num)
//   |         |
//   |         v
//   |      Apply previous operator (op) to result
//   |
//   +--> Else if expr[j] is operator '+', '-', '*', '/'
//   |         |
//   |         v
//   |      Store operator in op
//   |
//   +--> Else if expr[j] is '='
//             |
//             v
//           Break loop
//   |
//   v
// Print result
//   |
//   v
// End
