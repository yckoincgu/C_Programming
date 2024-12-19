#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getExpressionStr() {
    char *userInputStr = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter your arithmetic expression: ");

    // Dynamically allocate memory for user input with realloc
    read = getline(&userInputStr, &len, stdin);
    if (read == -1) {
        fprintf(stderr, "Error reading input\n");
        return NULL;
    }

    // Remove trailing newline (if present)
    size_t trimmed_len = strlen(userInputStr);
    if (trimmed_len > 0 && userInputStr[trimmed_len - 1] == '\n') {
        userInputStr[trimmed_len - 1] = '\0';
    }

    return userInputStr;
}

int main() {
    char *expression = getExpressionStr();
    if (expression == NULL) {
        return 1;
    }

    printf("You entered: %s\n", expression);

    // Process the expression here (e.g., parse, evaluate)
    // ...

    free(expression);
    return 0;
}