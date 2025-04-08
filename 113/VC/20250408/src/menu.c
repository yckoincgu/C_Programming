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

void printLogicalOperatorSymbol(char *operatorName, char *operatorSymbol, char *operatorCode, int strLength){
    int i=0;
    //printf("The length is %d \n", strLength);
    printf("%-25s: %-10s Operator Code is %-10s  \n",operatorName, operatorSymbol,operatorCode);
    for(i=0; i< strLength; i++)
        printf("%c", operatorSymbol[i]);
    printf("\n");    
}

void displayMenu() {
    clearScreen();
    printf("Logical atom like p, q, r, s, t, and so on \n");
    printf("Logical operators are listed below (Their code depends on systems) \n");
    printLogicalOperatorSymbol("Logical AND","\xE2\x88\xA7", "\\xE2\\x88\\xA7", strlen("\xE2\x88\xA7")*4);
    printLogicalOperatorSymbol("Logical OR","\xE2\x88\xA8", "\\xE2\\x88\\xA8", strlen("\xE2\x88\xA8")*4);
    printLogicalOperatorSymbol("Logical NOT","\xC2\xAC", "\\xC2\\xAC", strlen("\xC2\xAC")*4);
    printLogicalOperatorSymbol("Logical Implication","\xE2\x86\x92", "\\xE2\\x86\\x92", strlen("\xE2\x86\x92")*4);
    printLogicalOperatorSymbol("Logical Equivalence","\xE2\x86\x94", "\\xE2\\x86\\x94", strlen("\xE2\x86\x94")*4);
    printLogicalOperatorSymbol("Logical All","\xE2\x88\x80", "\\xE2\\x88\\x80", strlen("\xE2\x88\x80")*4);
    printLogicalOperatorSymbol("Logical Exists","\xE2\x88\x83", "\\xE2\\x88\\x83", strlen("\xE2\x88\x83")*4);
    printLogicalOperatorSymbol("Logical Therefore","\xE2\x88\xB4", "\\xE2\\x88\\xB4", strlen("\xE2\x88\xB4")*4);
    printLogicalOperatorSymbol("Logical Because","\xE2\x88\xB5", "\\xE2\\x88\\xB5", strlen("\xE2\x88\xB5")*4);
    printf("Parentheses: ( or )\n");
    printf("\n");
    
    printf("Please enter your logical expression below \n");
}