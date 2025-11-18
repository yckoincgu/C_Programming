#include <stdio.h>

int main() {
    char source[] = "You are welcome.";
    char destination[50];
    int i;
    
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0'; 

    printf("Copied string: %s\n", destination);
    
    return 0;
}
