#include <stdio.h>

int main(){
    int a=5;
    int *p=&a;
    int b=*p;
    printf("\n Value of b: %d\n", b);
    printf("\n Value of *p: %d\n", *p);

    int aSpace[5]={10,20,30,40,50};
    p=aSpace;
    for(int i=0;i<5;i++){
        printf("\n Value of aSpace[%d]: %d", i, *(p+i));
    }

}