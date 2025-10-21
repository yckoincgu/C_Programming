#include <stdio.h>

int main(){
    int a=5;
    int *p=&a;
    int b=*p;
    printf("\n Value of b: %d\n", b);
    printf("\n Value of *p: %d\n", *p);

}