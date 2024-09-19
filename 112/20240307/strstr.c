#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";

    char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("Substring found at position: %ld\n", result - haystack);
    } else {
        printf("Substring not found\n");
    }
    return 0;
}
