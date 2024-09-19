#include <stdio.h>
void EX01();
void EX02();         // function prototype

int main()
{

    EX01();
    EX02();
    return 0;
}

void EX01()         // function definition
{
    printf("Hello World\n");
}

void EX02()
{
    int number1, number2, sum;

    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // calculate the sum
    sum = number1 + number2;

    printf("%d + %d = %d\n", number1, number2, sum);
}
