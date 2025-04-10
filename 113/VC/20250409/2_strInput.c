#include <stdio.h>

int main(){

    char s[100]; // Buffer to store the input string
    char  x=34; // 34 is a double quote in character

    printf("Enter a string like hello world:  ");
    scanf("%s", s); // Reads until whitespace
    printf("The scanf function reads the first word in your input string %c%s%c\n", x,s,x);

    return 0;

}