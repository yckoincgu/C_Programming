#include <stdio.h>


// 函數用來顯示圖形A Function to display pattern A
void TFlogicA() {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j >= i ) printf("X");
            else printf(" ");
        }
        printf("\n");  // 換行 Newline after each row
    }
}


// 函數用來顯示圖形B Function to display pattern B
void TFlogicB() {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j >= 3-i ) printf("X");
            else printf(" ");
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
