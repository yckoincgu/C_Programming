#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // (A) Declare a pointer string s, size_t bufferSize = 0
    char *s = NULL;
    size_t bufferSize = 0;

    // (B) Declare character variable x for the double quote
    char x = 34; // ASCII value for double quote

    // (C) Reading the input string
    printf("Enter a string like hello world: ");
    if (getline(&s, &bufferSize, stdin) != -1) {
        // Remove trailing newline character
        char *newline = strchr(s, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        // Print the output as requested
        printf("The getline function read your string: %c%s%c\n", x, s, x);

        // (D) adding a line feed in the end of its printing.
        // The "\n" in the above printf statement already adds a line feed.
        // However, if you wanted another empty line, you could add:
        // printf("\n");

        free(s); // Free the allocated memory by getline
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}