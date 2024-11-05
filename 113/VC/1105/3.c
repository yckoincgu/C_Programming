#include <stdio.h>

int main()
{
    int number ;
    printf("Please enter one integer.\n");
    scanf("%d", &number);
    if(number > 20) {
        printf("The number bigger than 20\n");
    }else{
        printf("The number NOT bigger than 20\n");
    }


    return 0;
}
