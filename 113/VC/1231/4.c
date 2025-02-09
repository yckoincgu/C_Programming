#include <stdio.h>

void printBinary(int n) {

    if (n == 0) {
        printf("0");
        return;
    }

    char binary[32];
    int index = 0;

    while (n > 0) {
        binary[index] = (n % 2) + '0';
        n = n / 2;
        index++;
    }
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

int main() {
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    printf("Binary representation: ");
    printBinary(num);
    
    return 0;
}
