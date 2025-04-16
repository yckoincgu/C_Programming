#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern char *inputStringDynamic;
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

void displayMenu();
int getInputAndSetToHeap();
void freeInputStrings();
void printBinary(int x);

