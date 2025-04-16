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

long int operatorPosition(char *s){
    char *ptr;
    //long int position=0;
    ptr = strstr(s, "\xE2\x88\xA7"); //position=ptr;
    return (long int) ptr;
}
void printLogicExpression(char *s, int strLength){
    int start_position=0, end_position=strLength;
    char tempStr[strLength];
    char *ptr=NULL; ptr=s;
    int  i=0;
    while(start_position != end_position){
        start_position = (int) (strstr(ptr, "\xE2\x88\xA7")-s);
        for(i=0; i<start_position && s[i] != '\0'; i++)
            tempStr[i]=s[i];
        tempStr[i]='\0';    
        printf("You entered: %s\n", tempStr);    
    }

    printf("You entered: %s %s\n", tempStr , "\xE2\x88\xA7");

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
        int stringLength = strlen(inputStringDynamic);
        printLogicExpression(inputStringDynamic, stringLength);
        

        
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

void operatorTable(char *operatorName, char *operatorSymbol, char *operatorCode, int strLength){
    //int i=0;
    //printf("The length is %d \n", strLength);
    
    printf("%-25s %-17s %12s %15d \n",operatorName, operatorSymbol, operatorCode, strLength);
    //for(i=0; i< strLength; i++)
    //    printf("%c", operatorSymbol[i]);
    //printf("\n");    
}

void displayMenu() {
    clearScreen();
    printf("Logical atom like p, q, r, s, t, and so on \n");
    //printf("Logical operators are listed below (Their code depends on systems) \n");
    printf("%-20s %-20s %-20s %10s\n", "Operator Name ", "Operator Symbol", "Program Code", "string length");
    operatorTable("Logical AND","\xE2\x88\xA7", "\\xE2\\x88\\xA7", strlen("\xE2\x88\xA7")*4);
    operatorTable("Logical OR","\xE2\x88\xA8", "\\xE2\\x88\\xA8", strlen("\xE2\x88\xA8")*4);
    operatorTable("Logical NOT","\xC2\xAC", "\\xC2\\xAC ", strlen("\xC2\xAC")*4);
    operatorTable("Logical Implication","\xE2\x86\x92", "\\xE2\\x86\\x92", strlen("\xE2\x86\x92")*4);
    operatorTable("Logical Equivalence","\xE2\x86\x94", "\\xE2\\x86\\x94", strlen("\xE2\x86\x94")*4);
    operatorTable("Logical All","\xE2\x88\x80", "\\xE2\\x88\\x80", strlen("\xE2\x88\x80")*4);
    operatorTable("Logical Exists","\xE2\x88\x83", "\\xE2\\x88\\x83", strlen("\xE2\x88\x83")*4);
    operatorTable("Logical Therefore","\xE2\x88\xB4", "\\xE2\\x88\\xB4", strlen("\xE2\x88\xB4")*4);
    operatorTable("Logical Because","\xE2\x88\xB5", "\\xE2\\x88\\xB5", strlen("\xE2\x88\xB5")*4);
    printf("Parentheses: ( or )\n");
    printf("\n");
    
    printf("Please enter your logical expression below \n");
    getInputAndSetToHeap();
}