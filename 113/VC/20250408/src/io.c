#include "menu.h"

struct LogicalAtom logicalAtom[NO_OF_ATOMS]={{'p',0 },{'q',1},{'r',1},{'s',1},{'t',1}};

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
int inputLength=0;

int isLogicalSymbol(char *p, char*q, int wordLength);
int getAtomPosition(int startPosition, int endPosition);
int getWordLength(char *s);


// wchar_t unicode_to_wchar(const char *unicode_escape);



int getAtomValue(char c){
    int atomValue=-1, i=0;
    for(i=0; i<NO_OF_ATOMS; i++){
        if(logicalAtom[i].symbol == c) {
            atomValue=logicalAtom[i].value;
            break;
        }
    }
    return atomValue;
}
int getUnicodeCodePoint(const char* utf8) {
    if ((utf8[0] & 0xF0) == 0xE0 && (utf8[1] & 0xC0) == 0x80 && (utf8[2] & 0xC0) == 0x80) {
        // 3-byte UTF-8 sequence
        return ((utf8[0] & 0x0F) << 12) | ((utf8[1] & 0x3F) << 6) | (utf8[2] & 0x3F);
    } else if ((utf8[0] & 0xE0) == 0xC0 && (utf8[1] & 0xC0) == 0x80) {
        // 2-byte UTF-8 sequence
        return ((utf8[0] & 0x1F) << 6) | (utf8[1] & 0x3F);
    } else if (utf8[0] <= 0x7F) {
        // 1-byte ASCII
        return utf8[0];
    }
    return 0; // Invalid or unsupported UTF-8 sequence
}
int getLogicalSymbol(int startPosition, int endPosition){
    int i=0, j=0, atomPosition=0, symbolInt=0;
    //printf("The start position is %d endPosition is %d \n", startPosition, endPosition);
    atomPosition=getAtomPosition(startPosition, endPosition);
    //printf("The atom position is %d \n", atomPosition);
    char tmpArray[20];
    for (i=startPosition, j=0; i<atomPosition; i++,j++ )
        if(inputStringDynamic[i] == ' ') {tmpArray[j]='\0'; break;}
        else tmpArray[j]=inputStringDynamic[i];
    tmpArray[j]='\0';  // null-terminated character for C string
    symbolInt = getUnicodeCodePoint(tmpArray);
 
        switch(symbolInt) {
            case 0x2227: // Logical AND (∧)	
                symbolInt = 0x2227; // Logical AND
                break;
            case 0x2228: // Logical OR (∨)
                symbolInt = 0x2228; // Logical OR ('∨')
                break;
            case 0x00AC: // Unicode for '¬'
                symbolInt = 0x00AC; // Logical NOT
                break;
            case 0x2192: // Logical Implication (→)
                symbolInt = 0x2192; // Logical Implication
                break;
            case 0x2194: // Logical Equivalence (↔) 
                symbolInt = 0x2194; // Logical Equivalence
                break;
            case 0x2200: // Logical All (∀)
                symbolInt = 0x2200; // Logical All
                break;
            case 0x2203: // Logical Exists (∃)
                symbolInt = 0x2203; // Logical Exists
                break;
            case 0x2234: // Logical Therefore (∴)
                symbolInt = 0x2234; // Logical Therefore
                break;
            case 0x2235: // Logical Because (∵)
                symbolInt = 0x2235; // Logical Because
                break;
            default: symbolInt=0;        
        }
    //}    


    return symbolInt;

}
int parseAndCalculateAlgebra(int startPosition, int endPosition){
    int logicalResult=0, 
    leftAtomPosition=0, symbolInt=0;
    char *ptr=inputStringDynamic;

    while (*ptr != '\0') {
        while(*ptr == ' ')  {ptr++; startPosition++;}    // clear space
        leftAtomPosition=getAtomPosition(startPosition, endPosition);
        if (leftAtomPosition > startPosition) {            
            symbolInt=getLogicalSymbol(startPosition, leftAtomPosition);
            logicalResult=calculateAlgebra(logicalResult, symbolInt, getAtomValue(ptr[leftAtomPosition]));}
        else logicalResult=getAtomValue(ptr[leftAtomPosition]);
        startPosition=leftAtomPosition+1; // move to the next character
        if(startPosition < endPosition) ptr=&inputStringDynamic[startPosition];
        else break;
    }  
          
    return logicalResult;
}

int getAtomPosition(int startPosition, int endPosition){
    // convert a string to an integer
    int i=0, atomPosition=0;
    char *ptr=inputStringDynamic;

    i=startPosition;    // the first character in an expression
    
    while(ptr[i] != '\0') 
        if(getAtomValue(ptr[i]) > -1) {break;}    // not TRUE and not FALSE
        else i++;
    
    atomPosition=i;

    return atomPosition;
}

int isLogicalSymbol(char *p, char*q, int wordLength){
    // input character or string is a logical symbol
    // comparing 2 or 3 characters for a symbol
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

void printLogicExpressionBySpace(char *s, int strLength){
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
        printLogicExpressionBySpace(inputStringDynamic, inputLength);
        //printCharOfInput(inputLength);
    } else {
        printf("Error reading input.\n");
    }    

        

    return successFlag;
}

void freeInputStrings(){
    free(inputStringDynamic); // Free the dynamically allocated memory
    //printf("The allocated memory for input is freed already \n");    
}    


int getWordLength(char *s){
    char *ptr=s;
    int i=0;


    while(*ptr != '\0' && *ptr != SPACE) {
        ptr++; i++; 
    }
    
    return i;
}