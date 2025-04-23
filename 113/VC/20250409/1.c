#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main() {
    // Set the locale to UTF-8 to handle wide characters correctly
    if (setlocale(LC_ALL, "") == NULL) {
        printf("Locale setting failed.\n");
        return 1;
    }

    // Assign the "∧" symbol to a wide character array
    wchar_t symbolArray[2]; // Size 2: one for the symbol, one for the null terminator
    symbolArray[0] = L'\u2227'; // Assign the Unicode code point for "∧"
    symbolArray[1] = L'\0';       // Null-terminate the wide character array

    // Print the symbol from the array
    printf("The symbol is: %ls\n", symbolArray);

    return 0;
}
