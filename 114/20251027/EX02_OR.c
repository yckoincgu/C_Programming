#include <stdio.h>

int main() {
    char first_letter = 'A';
    char last_letter = 'Z';
    int is_special_letter;

    // Condition: first_letter is 'A' OR last_letter is 'A'
    is_special_letter = (first_letter == 'A') || (last_letter == 'A');

    printf("Result: %d\n", is_special_letter); // Output: 1 (True, because 'A' == 'A' is true)

    first_letter = 'B';
    is_special_letter = (first_letter == 'A') || (last_letter == 'A');

    printf("Result: %d\n", is_special_letter); // Output: 0 (False, because 'B' == 'A' is false AND 'Z' == 'A' is false)

    return 0;
}