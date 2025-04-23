#include "menu.h"


int main() {
    displayMenu();
    int inputInt=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        inputInt=atoi(inputStringDynamic);
        printBinary(inputInt);
    }
        


    freeInputStrings();

    return 0;
}
