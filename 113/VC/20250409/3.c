#include <locale.h>

#include <wchar.h>

#include "menu.h"

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





void freeInputStrings(){

free(inputStringDynamic); // Free the dynamically allocated memory

printf("The allocated memory for input is freed already \n");

}



void clearScreen() {

system("clear");

}



int getWordLength(char *s){

char *ptr=s, space=(int) 32;

int i=0;

while(*ptr != '\0' && *ptr != space) {

ptr++; i++;

}


return i;

}





void printLogicExpression(char *s, int strLength){

//int start_position=0, end_position=strLength;

char *ptr=s;

int wordLength=0, startPosition=1, i=0, j=0;

char tmpArray[20];

printf("\n starting analysis\n");

while(startPosition <= strLength){

wordLength=getWordLength(ptr);



for (i=startPosition, j=0; i<startPosition+wordLength; i++, j++ )

if(s[i-1] == '\\') tmpArray[j]='\\';

else tmpArray[j]=s[i-1];

tmpArray[wordLength] ='\0';

printf("test %s\n", tmpArray);


//printf("\n");

//printf("wordLength = %d\n", wordLength);


ptr = ptr+wordLength+1; // the first character in an expression

startPosition=startPosition+wordLength+1; // segment with twp positions

//printf("startPosition= %d\n", startPosition);

}

printf("\n");

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

*newlineChar = '\0'; // null-terminated character for C string

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



void operatorTable(char *operatorName, char *operatorSymbol_Pointer, char *operatorCode, int strLength){

//int i=0;

//printf("The length is %d \n", strLength);


printf("%-25s %-17s %12s %15d \n",operatorName, operatorSymbol_Pointer, operatorCode, strLength);

//for(i=0; i< strLength; i++)

// printf("%c", operatorSymbol_Pointer[i]);

//printf("\n");

}



void displayMenu() {

clearScreen();


printf("Logical atom like p, q, r, s, t, and so on \n");

//printf("Logical operators are listed below (Their code depends on systems) \n");

printf("%-20s %-20s %-20s %10s\n", "Operator Name ", "Symbol_Pointer", "Pointer Code", "string length");

operatorTable("Logical AND",Logical_AND_Symbol_Pointer, Logical_AND_code, strlen(Logical_AND_Symbol_Pointer));

operatorTable("Logical OR",Logical_OR_Symbol_Pointer, Logical_OR_code, strlen(Logical_OR_Symbol_Pointer));

operatorTable("Logical NOT",Logical_NOT_Symbol_Pointer, Logical_NOT_code, strlen(Logical_NOT_Symbol_Pointer));

operatorTable("Logical Implication",Logical_Implication_Symbol_Pointer, Logical_Implication_code, strlen(Logical_Implication_Symbol_Pointer));

operatorTable("Logical Equivalence",Logical_Equivalence_Symbol_Pointer, Logical_Equivalence_code, strlen(Logical_Equivalence_Symbol_Pointer));

operatorTable("Logical All",Logical_All_Symbol_Pointer, Logical_All_code, strlen(Logical_All_Symbol_Pointer));

operatorTable("Logical Exists",Logical_Exists_Symbol_Pointer, Logical_Exists_code, strlen(Logical_Exists_Symbol_Pointer));

operatorTable("Logical Therefore",Logical_Therefore_Symbol_Pointer, Logical_Therefore_code, strlen(Logical_Therefore_Symbol_Pointer));

operatorTable("Logical Because",Logical_Because_Symbol_Pointer, Logical_Because_code, strlen(Logical_Because_Symbol_Pointer));

printf("LeftParentheses: ( \n");

printf("RightParentheses: ) \n");

printf("Logical statements: P, Q, R, T \n");

printf("\n");


printf("Please enter your logical expression below \n");

getInputAndSetToHeap();

}