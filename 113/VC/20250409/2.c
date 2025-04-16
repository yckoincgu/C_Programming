#include <stdio.h>

int main()
{
    char s[25]; 
    char x = '\"';  

    printf("Enter a string like hello world:  "); 
    scanf("%s", s);

    printf("The scanf function reads the first word in your input string %c%s%c\n", x, s, x);

    return 0;
}
