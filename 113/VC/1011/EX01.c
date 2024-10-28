#include <stdio.h>


// 函數用來顯示圖形A Function to display pattern A
void TFlogicA() {
    int i, j, space;

    // 外層迴圈控制每一行 Outer loop controls the rows
    for (i = 5; i > 0; i--) {
        // 顯示前置空格 Show leading spaces
        for (space = 0; space < 5 - i; space++) {
            printf(" ");
        }

        // 顯示星號 Show the stars ('x')
        for (j = 0; j < i; j++) {
            printf("x");
        }

        printf("\n");  // 換行 Newline after each row
    }
}


// 函數用來顯示圖形B Function to display pattern B
void TFlogicB() {
    int i, j, space;

    // 外層迴圈控制每一行 Outer loop controls the rows
    for (i = 1; i <= 5; i++) {
        // 顯示前置空格 Show leading spaces
        for (space = 0; space < 5 - i; space++) {
            printf(" ");
        }

        // 顯示星號 Show the stars ('x')
        for (j = 0; j < i; j++) {
            printf("x");
        }

        printf("\n");  // 換行 Newline after each row
    }
}


int main() {
    // 顯示圖形A Display pattern A
    printf("(A)\n");
    TFlogicA();

    // 顯示圖形B Display pattern B
    printf("(B)\n");
    TFlogicB();


    return 0;
}
