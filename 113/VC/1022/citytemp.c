#include <stdio.h>

float citytemp[4][4];
int i,ii,sequence;

int main(){
    for (i=0;i<4;i++){
        for (ii=0;ii<4;ii++){
        sequence = i*4+ii+1;
        printf("請輸入第 %d 個數值: \n",sequence);
        scanf("%f",&citytemp[i][ii]);
        }
    }
    printf("       Jan.   Feb.   Mar.   Apr. \n");
    for (i=0;i<4;i++) {
        printf("%c    ",'A'+i);
        for (ii=0;ii<4;ii++) 
            printf("%-7.2f",citytemp[i][ii]);
        printf("\n");
    } 
}