#include <stdio.h>

void toBinary(int number) {
    if (number == 0) {
        printf("二進位: 0\n");
        return;
    }
    int remainders[32]; 
    int index = 0;      

    while (number > 0) {
        remainders[index] = number % 2;
        index+=1;
        number/=2;                
    }
    printf("二進位: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", remainders[i]);
    }
    printf("\n");
}

int main() {
    int number;
    printf("請輸入一個整數: ");
    scanf("%d", &number);
    toBinary(number);
    return 0;
}
