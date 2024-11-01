#include <stdio.h>

int i,j;

int main(){
    for (i=4;i>0;i--) {
        for (j=2;j<6;j++){
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
