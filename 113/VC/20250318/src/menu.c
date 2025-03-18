#include "menu.h"

char *inputStringDynamic = NULL;

void freeInputStrings(){
    free(inputStringDynamic); // Free the dynamically allocated memory
    printf("The allocated memory for input is freed already \n");    
}    

void clearScreen() {
    system("clear");
}

int getInputAndSetToHeap(){
    // Dynamic allocation example
    int successFlag=1;

    size_t bufferSize = 0;

    if (getline(&inputStringDynamic, &bufferSize, stdin) != -1) {
        // Remove trailing newline character, if present
        char *newline = strchr(inputStringDynamic, '\n');
        // strchr: locating the first occurrence of a character within a string
        if (newline != NULL) {
            *newline = '\0';    // null-terminated character for C string
        }

        printf("You entered: %s\n", inputStringDynamic);
        int stringLength = strlen(inputStringDynamic);
        printf("Analysis of your input is presented below\n");
        printf("The length of %s is %d \n", inputStringDynamic, stringLength);
        int i=0;
        for(i=0; i< stringLength; i++){
            if(i==0 && inputStringDynamic[i]=='-') continue;    
            if(!(inputStringDynamic[i]>='0' && inputStringDynamic[i]<='9')){
                successFlag=0;
                printf("%c is an error digit \n", inputStringDynamic[i]);
            }
            else printf("%c\n", inputStringDynamic[i]);
        }   
    } else {
        printf("Error reading input.\n");
        successFlag=0;
    }
    return successFlag;
}

void displayMenu() {
    clearScreen();
    printf("Please enter your decimal integer below \n");
}