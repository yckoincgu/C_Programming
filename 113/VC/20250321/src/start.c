#include <string.h>
#include "menu.h"

int main() {
    clearScreen();
    displayMenu();
    
    int x;
    printf("Enter decimal integer: ");
    scanf("%d", &x);
    
    // Your main logic here
    
    return 0;
}