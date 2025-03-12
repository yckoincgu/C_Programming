#include <stdio.h>
#include <string.h>

void getString(char *buffer, int bufferSize) {
    strncpy(buffer, "Hello !", bufferSize - 1);
    buffer[bufferSize - 1] = '\0'; // Ensure null termination
    printf("bufferSize is %d\n", bufferSize - 1); 
}

int main() {
    char str[20];
    getString(str, sizeof(str));
    printf("the size of str is %d\n", (int)sizeof(str));
    int i=0;
    for(i=0; i<(int)sizeof(str); i++)
        if (str[i]== '\0') break;
        printf("the length of str is %d\n", i);    
    printf("%s\n", str);
    return 0;
}