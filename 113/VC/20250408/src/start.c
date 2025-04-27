#include "menu.h"


int main() {
    displayMenu();
    int logicalResult=0;
    //int inputInt=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        //logicalResult=calculateAlgebra(1, 0x2227, 0);
        logicalResult=parseAndCalculateAlgebra(0, inputLength);
        //printf("The result of logical expression is: %d \n", logicalResult);
        printf("Result: %d\n", logicalResult);
        printf("test main \n");

    }
        


    freeInputStrings();

    return 0;
}
