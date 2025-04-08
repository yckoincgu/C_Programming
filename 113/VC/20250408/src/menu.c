#include <locale.h>
#include <wchar.h>
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
        // Remove trailing newlineChar character, if present
        char *newlineChar = strchr(inputStringDynamic, '\n');
        // strchr: locating the first occurrence of a character within a string
        if (newlineChar != NULL) {
            *newlineChar = '\0';    // null-terminated character for C string
        }

        printf("You entered: %s\n", inputStringDynamic);
        int stringLength = strlen(inputStringDynamic);
        printf("Analysis of your input is presented below\n");
        printf("The length of %s is %d \n", inputStringDynamic, stringLength);
        int i=0;
        for(i=0; i< stringLength; i++){ 
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
    printf("Logical atom like p, q, r, s, t, and so on \n");
    printf("Logical AND: %s\n", "\xE2\x88\xA7"); // ∧
    printf("Logical OR: %s\n", "\xE2\x88\xA8");  // ∨
    printf("Logical NOT: \xC2\xAC\n");    // ¬
    printf("Logical Implication: \xE2\x86\x92\n"); // →
    printf("Logical Equivalence: \xE2\x86\x94\n"); // ↔
    printf("For All: \xE2\x88\x80\n");      // ∀
    printf("There Exists: \xE2\x88\x83\n"); // ∃
    printf("Therefore: \xE2\x88\xB4\n");   // ∴
    printf("Because: \xE2\x88\xB5\n");     // ∵

    printf("Logical operators like  \n");
    printf("Please enter your logical expression below \n");
}