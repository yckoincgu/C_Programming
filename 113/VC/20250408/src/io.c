#include "menu.h"
#include "logical_definitions.h"

struct LogicalAtom logicalAtom[5]={{'p',0 },{'q',0},{'r',0},{'s',0},{'t',0}};

char *Logical_AND_Symbol_Pointer="\u2227",
     *Logical_AND_code="\\u2227",
     *Logical_OR_Symbol_Pointer="\u2228",
     *Logical_OR_code="\\u2228",
     *Logical_NOT_Symbol_Pointer="\u00AC",
     *Logical_NOT_code="\\u00AC",
     *Logical_Implication_Symbol_Pointer="\u2192",
     *Logical_Implication_code="\\u2192",
     *Logical_Equivalence_Symbol_Pointer="\u2194",
     *Logical_Equivalence_code="\\u2194",
     *Logical_All_Symbol_Pointer="\u2200",
     *Logical_All_code="\\u2200",
     *Logical_Exists_Symbol_Pointer="\u2203",
     *Logical_Exists_code="\\u2203",
     *Logical_Therefore_Symbol_Pointer="\u2234",
     *Logical_Therefore_code="\\u2234",
     *Logical_Because_Symbol_Pointer="\u2235",
     *Logical_Because_code="\\u2235";

char *inputStringDynamic = NULL;

int isLogicalSymbol(char *p, char*q, int wordLength);

// wchar_t unicode_to_wchar(const char *unicode_escape);

void freeInputStrings(){
    free(inputStringDynamic); // Free the dynamically allocated memory
    printf("The allocated memory for input is freed already \n");    
}    


int getWordLength(char *s){
    char *ptr=s, space=(int) 32;
    int i=0;
    while(*ptr != '\0' && *ptr != space) {
        ptr++; i++; 
    }
    
    return i;
}

int isLogicalSymbol(char *p, char*q, int wordLength){
    char *qtr=q;    // Symbol_pointer
         
    int i=0, matchSymbol=1, // suppose match symbol at first
    result=0;
    
    
    for(i=0; i<wordLength; i++){
        if((int)p[i] == 92) {continue;};
        if(abs((int)p[i] - (int)(*qtr)) == 0) {qtr++;}
        else {matchSymbol =0; break;}
    }    
    if(matchSymbol) result=1;
    else result=0;

    return result;
}

void printCharOfInput(int inputLength){
    printf("Analysis of input character is presented below\n");
    printf("The length of %s is %d \n", inputStringDynamic, inputLength);
    int i=0;
    for(i=0; i< inputLength; i++){ 
        if(!(inputStringDynamic[i]>='0' && inputStringDynamic[i]<='9'))
            printf("%c is an error digit \n", inputStringDynamic[i]);
        else printf("%c\n", inputStringDynamic[i]);
    }
}

void printLogicExpression(char *s, int strLength){
    //int start_position=0, end_position=strLength;
    char *ptr=s;
    int wordLength=0, startPosition=0, i=0, j=0;
    char tmpArray[20];

    
    while(startPosition < strLength){
        wordLength=getWordLength(ptr);

        for (i=startPosition, j=0; i<startPosition+wordLength; i++, j++ )
            //printf("%c", s[i-1]);
            tmpArray[j]=s[i];
        tmpArray[j] ='\0';  

        if(isLogicalSymbol(tmpArray, "u2227", strlen(tmpArray))==1) printf("%s ",Logical_AND_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2228", strlen(tmpArray))==1) printf("%s ",Logical_OR_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u00AC", strlen(tmpArray))==1) printf("%s ",Logical_NOT_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2192", strlen(tmpArray))==1) printf("%s ",Logical_Implication_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2194", strlen(tmpArray))==1) printf("%s ",Logical_Equivalence_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2200", strlen(tmpArray))==1) printf("%s ",Logical_All_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2203", strlen(tmpArray))==1) printf("%s ",Logical_Exists_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2234", strlen(tmpArray))==1) printf("%s ",Logical_Therefore_Symbol_Pointer);
        else if(isLogicalSymbol(tmpArray, "u2235", strlen(tmpArray))==1) printf("%s ",Logical_Because_Symbol_Pointer);
        else {printf("%s ", tmpArray);}

        ptr = ptr+wordLength;   // the first character in an expression
        i=0;
        while(*ptr == ' ')  {ptr++;i++;}
        startPosition=startPosition+wordLength+i;   // segment with twp positions
    }
    printf("\n\n"); 
}

int getInputAndSetToHeap(){
    // Dynamic allocation example
    int successFlag=1;
    int inputLength=0;
    size_t bufferSize = 0;
    printf("%30s", "Please enter your logical expression:  ");
    if (getline(&inputStringDynamic, &bufferSize, stdin) != -1) {
        // Remove trailing newlineChar character, if present
        char *newlineChar = strchr(inputStringDynamic, '\n');
        // strchr: locating the first occurrence of a character within a string
        if (newlineChar != NULL) {
            *newlineChar = '\0';    // null-terminated character for C string
        }
        inputLength = strlen(inputStringDynamic);
        printf("%30s   ", "Your input logical statement is:  ");
        printLogicExpression(inputStringDynamic, inputLength);
        //printCharOfInput(inputLength);
    } else {
        printf("Error reading input.\n");
    }    

        

    return successFlag;
}