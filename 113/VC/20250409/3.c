#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = NULL;            
    size_t bufferSize = 0;      
    char x = '\"'; 

    printf("Enter a string like hello world:  ");

    getline(&s, &bufferSize, stdin);


    printf("The getline function read your string: %c%s%c\n", x, s, x);

    free(s);

    return 0;
}
