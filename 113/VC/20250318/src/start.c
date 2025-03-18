#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main() {
    displayMenu();
    int x=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        x=atoi(inputStringDynamic);
        printBinary(x);
    }
        


    freeInputStrings();

    return 0;
}
