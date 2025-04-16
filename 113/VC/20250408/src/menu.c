#include <locale.h>
#include <wchar.h>
#include "menu.h"
char *Logical_AND_Symbol="\xE2\x88\xA7",
     *Logical_AND_code="\\xE2\\x88\\xA7",
     *Logical_OR_Symbol="\xE2\x88\xA8",
     *Logical_OR_code="\\xE2\\x88\\xA8",
     *Logical_NOT_Symbol="\xC2\xAC",
     *Logical_NOT_code="\\xC2\\xAC",
     *Logical_Implication_Symbol="\xE2\x86\x92",
     *Logical_Implication_code="\\xE2\\x86\\x92",
     *Logical_Equivalence_Symbol="\xE2\x86\x94",
     *Logical_Equivalence_code="\\xE2\\x86\\x94",
     *Logical_All_Symbol="\xE2\x88\x80",
     *Logical_All_code="\\xE2\\x88\\x80",
     *Logical_Exists_Symbol="\xE2\x88\x83",
     *Logical_Exists_code="\\xE2\\x88\\x83",
     *Logical_Therefore_Symbol="\xE2\x88\xB4",
     *Logical_Therefore_code="\\xE2\\x88\\xB4",
     *Logical_Because_Symbol="\xE2\x88\xB5",
     *Logical_Because_code="\\xE2\\x88\\xB5";
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
    char *ptr=s, *qtr=NULL;
    int  i=0;
    printf("starting analysis\n");
    while(start_position != strLength){
        
        ptr = strstr(ptr, "\\x");   // the first symbol in an expression
        
        
        if (ptr == NULL) {
            start_position=end_position+12;
            end_position=strLength;
            for(i=start_position; i < end_position && s[i] != '\0'; i++) printf("%c", s[i]); 
            break;
        }
        

        end_position=(int)(ptr-s);
        for(i=start_position; i < end_position && s[i] != '\0'; i++) 
            printf("%c", s[i]);
        
        qtr=ptr;
        while( qtr != NULL){

        }    

        start_position=end_position+12;    
        ptr = ptr + start_position;   
    }
    printf("\n"); 

    //printf("You entered: %s %s\n", tempStr , "\xE2\x88\xA7");

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
    operatorTable("Logical AND",Logical_AND_Symbol, Logical_AND_code, strlen(Logical_AND_Symbol)*4);
    operatorTable("Logical OR",Logical_OR_Symbol, Logical_OR_code, strlen(Logical_OR_Symbol)*4);
    operatorTable("Logical NOT",Logical_NOT_Symbol, Logical_NOT_code, strlen(Logical_NOT_Symbol)*4);
    operatorTable("Logical Implication",Logical_Implication_Symbol, Logical_Implication_code, strlen(Logical_Implication_Symbol)*4);
    operatorTable("Logical Equivalence",Logical_Equivalence_Symbol, Logical_Equivalence_code, strlen(Logical_Equivalence_Symbol)*4);
    operatorTable("Logical All",Logical_All_Symbol, Logical_All_code, strlen(Logical_All_Symbol)*4);
    operatorTable("Logical Exists",Logical_Exists_Symbol, Logical_Exists_code, strlen(Logical_Exists_Symbol)*4);
    operatorTable("Logical Therefore",Logical_Therefore_Symbol, Logical_Therefore_code, strlen(Logical_Therefore_Symbol)*4);
    operatorTable("Logical Because",Logical_Because_Symbol, Logical_Because_code, strlen(Logical_Because_Symbol)*4);
    printf("LeftParentheses:  ( \n");
    printf("RightParentheses: ) \n");
    printf("\n");
    
    printf("Please enter your logical expression below \n");
    getInputAndSetToHeap();
}