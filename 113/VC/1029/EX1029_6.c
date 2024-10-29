#include <stdio.h>

int main() {

    int i, j;

    printf("   J\n");
    printf("   j=0  j=1  j=2  j=3\n");

    
    for (i = 0; i < 4; i++) {
        printf("i=%d ", i);
        for (j = 0; j < 4; j++) {
            // 
            if (i == 0) {
                printf("%s  ", (j < 4) ? "X" : " ");
            } else if (i == 1) {
                printf("%s  ", (j == 0) ? " " : "X");
            } else if (i == 2) {
                printf("%s  ", (j < 2) ? " " : "X");
            } else if (i == 3) {
                printf("%s  ", (j < 3) ? " " : "X");
            }
        }
        printf("\n");
    }

    return 0;
}