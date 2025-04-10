#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (A) Declare a getStr function with return a string pointer
char *getStr() {
    char *s = NULL;
    size_t bufferSize = 0;

    printf("Enter a string like hello world: ");
    if (getline(&s, &bufferSize, stdin) != -1) {
        char *newline = strchr(s, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        return s; // Return the dynamically allocated string
    } else {
        return NULL; // Return NULL on error
    }
}

int main() {
    // (B) Declare variables like (3)
    char *inputString = NULL;
    char x = 34; // Double quote
    int result;

    // (C) Get the input string from getStr
    inputString = getStr();

    if (inputString != NULL) {
        printf("The getline function succeeded in reading the input\n");
        printf("The getStr function : %c%s%c\n", x, inputString, x);

        free(inputString); // Free the allocated memory

    } else {
        printf("Error reading input.\n");
    }

    // (D) adding a line feed in the end of its printing of main().
    // The "\n" in the above printf statement already adds a line feed.
    // However, if you wanted another empty line, you could add:
    // printf("\n");

    return 0;
}