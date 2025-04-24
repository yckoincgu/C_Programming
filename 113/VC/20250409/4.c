#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Set locale for UTF-8

    char input[10]; // Array to store input (adjust size as needed)
    printf("Enter a character (including ∧): ");
    scanf("%9s", input); // Read up to 9 characters to prevent buffer overflow.  Use %s for char array input.

    printf("Integer values of the bytes entered for character ∧:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        printf("input[%d] = %u (unsigned), %d (signed)\n", i, (unsigned char)input[i], (signed char)input[i]);
        //  %u for unsigned decimal, %d for signed decimal
    }

    return 0;
}
