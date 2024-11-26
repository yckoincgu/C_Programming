#include <stdio.h>

char userInputStr[100]; // Adjust size as needed

char *getExpressionStr() {
    printf("Enter your arithmetic expression: ");
    fgets(userInputStr, sizeof(userInputStr), stdin);

    // Remove trailing newline character, if present
    char *pointerAtNewLineChar = strchr(userInputStr, '\n');    // return pointer at the new line character
    if (pointerAtNewLineChar) {
        *pointerAtNewLineChar = '\0';
    }

    return userInputStr;
}

int main(){

    getExpressionStr();
    printf("your arithmetic expression: %s", userInputStr);
    printf("\n");

    return 0;
}