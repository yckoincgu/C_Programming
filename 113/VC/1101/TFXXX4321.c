#include <stdio.h>

int i,j;

int main(){
    for (i=0;i<5;i++) {
        for (j=1;j<5;j++){
            if (j>i){
                printf("x");
                continue;
            }
            printf(" ");
            }
        printf("\n");
    }
    return 0;
}
