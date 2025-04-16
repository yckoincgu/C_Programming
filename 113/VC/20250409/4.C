#include <stdio.h>
#include <stdlib.h>

void getStr(char *str) {
    printf("The getStr function : \"%s\"\n", str);
}

int main() {
    size_t bufferSize = 256; 
    char *line = malloc(bufferSize); 

    if (line == NULL) {
        perror("Unable to allocate buffer");
        return 1;
    }

    printf("Enter a string like hello world: ");
    if (fgets(line, bufferSize, stdin) != NULL) {
        printf("The getline function succeeded in reading the input\n");
        printf("You entered: %s", line);
        getStr(line); 
    } else {
        printf("Error reading input\n");
    }

    free(line); 
    return 0;
}


