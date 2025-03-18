#include <stdio.h>
void displayMenu();
int getInputAndSetToHeap();
void freeInputStrings();

int main() {

    displayMenu();
    if(getInputAndSetToHeap()<1) 
        printf("Error input \n");
    freeInputStrings();

    return 0;
}
