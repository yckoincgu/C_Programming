#include <stdio.h>
#include <stdlib.h>

// Function declaration
char* transfer(int x);

int main(){
    int x;
    printf("please input decimal integer : ");
    scanf("%d",&x);
    char* result = transfer(x); 
    printf("binary result = %s",result);
    
    // Don't forget to free the allocated memory
    free(result);
    
    return 0;
}