#include <stdio.h>

int main() {
    int x, q, length=0;
    printf("Please enter a integer number: ");
    scanf("%d",&x);
    q=x;
    for(length=0; q>0; length++){
        q=q/10;
    }

    printf("digit length = %d \n", length);



    return 0;
}