#include "menu.h"


int main() {
    displayMenu();
    int logicalResult=0;
    //int inputInt=0;
    if(getInputAndSetToHeap()>0) {  // if succeed
        //logicalResult=calculateAlgebra(1, 0x2227, 0);
        logicalResult=parseAndCalculateAlgebra(0, inputLength);
        //printf("The inputLength is: %d \n", inputLength);
        if (logicalResult == 0) printf("The logical algebra value is False\n");
        if (logicalResult == 1) printf("The logical algebra value is True\n");
        

    }
        


    freeInputStrings();

    return 0;
}
