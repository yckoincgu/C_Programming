#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char *s = NULL;
    size_t bufferSize = 0;

    
    char x = '"';

    
    printf("Enter a string like hello world: ");

    
    getline(&s, &bufferSize, stdin); 
    char *ptr=s;
    while (*ptr != '\n'){
        ptr++;

    }
    *ptr='\0';
    
    printf("%c%s%c\n", x, s, x); 

  
    free(s);

    return 0;
}
