#include <stdio.h>

int main() {
 
int myInteger;
char myCharacter;
float myFloat;
double myDouble;

 printf("輸入一個整數: ");
    scanf("%d", &myInteger);
 printf("輸入一個字元: ");
    scanf(" %c", &myCharacter); 
 printf("輸入一個浮點數: ");
    scanf("%f", &myFloat);
 printf("輸入一個雙精度浮點數: ");
    scanf("%lf", &myDouble);
 
printf("\n您輸入了:\n");
    printf("整數: %d\n", myInteger);
    printf("字元: %c\n", myCharacter);
    printf("浮點數: %.2f\n", myFloat);
    printf("雙精度浮點數: %.2lf\n", myDouble);

}
























