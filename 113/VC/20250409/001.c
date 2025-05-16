#include <stdio.h>

void printBinary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int input;
    printf("請輸入一個整數：");
    scanf("%d", &input);

    unsigned char absValue = (input < 0) ? -input : input;

    printf("絕對值二進位表示：");
    printBinary(absValue);
    printf("\n");

    if (input < 0) {
        // 若原本是負數，模擬其補數過程
        unsigned char inverted = ~absValue;
        printf("步驟1. 反轉位元：");
        printBinary(inverted);
        printf("\n");

        unsigned char result = inverted + 1;
        printf("步驟2. 加1（補數）：");
        printBinary(result);
        printf("\n");
    }

    return 0;
}
