#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main() {
    displayMenu();
    int intStr=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        intStr=atoi(inputStringDynamic);
        printBinary(intStr);
    }
        


    freeInputStrings();

    return 0;
}
