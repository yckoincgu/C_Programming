#include "menu.h"


int main() {
    displayMenu();
    int logicalResult=0;
    //int inputInt=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        logicalResult=calculateAlgebra(1, 0x2227, 0);
        printf("Result: %d\n", logicalResult);
        printf("test main \n");

    }
        


    freeInputStrings();

    return 0;
}
