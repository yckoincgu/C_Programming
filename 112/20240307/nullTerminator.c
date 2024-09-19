#include <stdio.h>
#include <string.h>	// strlen

int main() {
    char myString[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Explicitly include the null character
	// '\0' is called as null-terminator, i.e. the end of a string
	
    printf("String: %s\n", myString);
    printf("Length of myString: %d\n", strlen(myString));

    return 0;
}

