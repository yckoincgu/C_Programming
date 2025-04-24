#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Set locale for UTF-8

    char input[10]; // Array to store input (adjust size as needed)
    printf("Enter a character (including ∧): ");
    scanf("%9s", input); // Read up to 9 characters to prevent buffer overflow

    printf("Integer values of the bytes entered for character ∧:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        printf("input[%d] = %d (signed), %u (unsigned), 0x%X (hex)\n",
               i, (signed char)input[i], (unsigned char)input[i], (unsigned char)input[i]);
    }

    return 0;
}
