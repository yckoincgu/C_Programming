#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    char *s = NULL;
    size_t bufferSize = 0;
    char  x=34; // 34 is a double quote in character

    printf("Enter a string like hello world:  ");
    if (getline(&s, &bufferSize, stdin) != -1) {
        // Remove trailing newline character, if present
        char *newline = strchr(s, '\n');
        // strchr: locating the first occurrence of a character within a string
        if (newline != NULL) {
            *newline = '\0';    // null-terminated character for C string
        }
        printf("The getline function read your string: %c%s%c\n", x,s,x);
    }    
    else
    printf("The getline function read error.\n");
    return 0;

}