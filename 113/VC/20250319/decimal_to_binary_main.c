#include <stdio.h>

int main(){
    int x;
    printf("please input decimal integer : ");
    scanf("%d",&x);
    char* result = transfer(x); 
    printf("binary result = %s",result);
    return 0;
}