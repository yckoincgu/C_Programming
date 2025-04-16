#include <stdio.h>

int main() {
    // (A) Declare a string array s with size 25 characters space
    char s[25];

    // (B) Declaring a character variable x for the double quote
    char x = 34; // ASCII value for double quote

    // (C) Reading the input string
    printf("Enter a string like hello world: ");
    scanf("%24s", s); // Read up to 24 characters (leaving space for null terminator)

    // Print the output as requested
    printf("The scanf function reads the first word in your input string %c%s%c\n", x, s, x);

    // (D) adding a line feed in the end of its printing.
    // The "\n" in the above printf statement already adds a line feed.
    // However, if you wanted another empty line, you could add:
    // printf("\n");

    return 0;
}