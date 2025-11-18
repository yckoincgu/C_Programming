#include <stdio.h>

int main() {

    int myInt;
    char myChar;
    float myFloat;
    double myDouble;

    printf("Enter an integer: ");
    scanf("%d", &myInt);

    printf("Enter a character: ");
    scanf(" %c", &myChar);

    printf("Enter a float: ");
    scanf("%f", &myFloat);

    printf("Enter a double: ");
    scanf("%lf", &myDouble);

   
    printf("\nYou entered:\n");
    printf("Integer: %d\n", myInt);
    printf("Character: %c\n", myChar);
    printf("Float: %f\n", myFloat);
    printf("Double: %lf\n", myDouble);

    return 0;
}
//+--------+--------+--------+--------+
//| myInt  | myInt  | myInt  | myInt  |  <-- 4 bytes
//+--------+--------+--------+--------+
//| myChar | PAD    | PAD    | PAD    |  <-- 1 byte char + 3 bytes padding
//+--------+--------+--------+--------+
//| myFloat               |  <-- 4 bytes
//+-----------------------+
//| PAD   | PAD   | PAD   | PAD   |  <-- alignment padding for double
//+-----------------------+
//| myDouble                     |  <-- 8 bytes
//+-------------------------------+