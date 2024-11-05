#include <stdio.h>

int main() {
    int count = 0; 

    while (count < 16) { 
        printf("* ");
        count++;

        if (count % 4 == 0) { 
            printf("\n");
        }
    }

    return 0;
}





