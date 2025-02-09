#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

double evaluateExpression(char *expression) {
    double numbers[100];
    char operators[100];
    int numIndex = 0, opIndex = 0;
    int i = 0;

    while (expression[i] != '\0') {
        if (isdigit(expression[i]) || expression[i] == '.') {
            char numStr[20];
            int j = 0;
            while (isdigit(expression[i]) || expression[i] == '.') {
                numStr[j++] = expression[i++];
            }
            numStr[j] = '\0';
            numbers[numIndex++] = atof(numStr);
        } else if (strchr("+-*/", expression[i])) {
            operators[opIndex++] = expression[i++];
        } else {
            i++;
        }
    }

    for (i = 0; i < opIndex; i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            numbers[i] = calculate(numbers[i], numbers[i + 1], operators[i]);
            for (int j = i + 1; j < numIndex - 1; j++) {
                numbers[j] = numbers[j + 1];
            }
            for (int j = i; j < opIndex - 1; j++) {
                operators[j] = operators[j + 1];
            }
            numIndex--;
            opIndex--;
            i--;
        }
    }

    double result = numbers[0];
    for (i = 0; i < opIndex; i++) {
        result = calculate(result, numbers[i + 1], operators[i]);
    }

    return result;
}

int main() {
    char expression[256];
    printf("請輸入表達式");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';
    double result = evaluateExpression(expression);
    printf("計算結果: %.2f\n", result);

    return 0;
}
