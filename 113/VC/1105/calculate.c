#include <stdio.h>

char op;
int num1,num2;

int main(){
    printf("請輸入第一個數字: ");
    scanf("%d", &num1);
    printf("請輸入第二個數字: ");
    scanf("%d", &num2);
    printf("請輸入運算符號 (+, -, *, /): ");
    scanf(" %c", &op);
    switch (op) {
        case '+':
            printf("結果: %d\n", num1 + num2);
            break;
        case '-':
            printf("結果: %d\n", num1 - num2);
            break;
        case '*':
            printf("結果: %d\n", num1 * num2);
            break;
        case '/':
         printf("結果: %d\n", num1 / num2);
         break;
            }
            return 0;
}