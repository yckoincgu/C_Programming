#include "menu.h"



void clearScreen() {
    system("clear");
}


void operatorTable(char *operatorName, char *operatorSymbol_Pointer, char *operatorCode, int strLength){

    printf("%-25s %-17s %12s %15d \n",operatorName, operatorSymbol_Pointer, operatorCode, strLength);
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
    printf("LeftParentheses:  ( \n");
    printf("RightParentheses: ) \n");
    printf("Logical statements: P, Q, R, T \n");
    printf("\n");
    

    //getInputAndSetToHeap();
}