#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logical_definitions.h"

extern char *inputStringDynamic;
extern int inputLength;

void displayMenu();
int getInputAndSetToHeap();
void freeInputStrings();
void printBinary(int x);
int calculateAlgebra(int result, int operatorChar, int num);
int parseAndCalculateAlgebra(int startPosition, int endPosition);

