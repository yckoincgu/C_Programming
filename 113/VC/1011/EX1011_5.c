#include <stdio.h>

int i,ii,sora;

int main(){

    for (i=5;i>0;i--) {
        for (sora=5;sora>i;sora--){
            printf(" ");
        }
        for (ii=0;ii<i;ii++){
            printf("x");
        }
        printf("\n");
    }
    return 0;
}