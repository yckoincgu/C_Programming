#include <stdio.h>

int main() {
    int day_number = 3;

    printf("Switching on day number %d...\n", day_number);

    switch (day_number) {
        case 1:
            printf("It's Monday.\n");
            break; // Exits the switch block
        case 2:
            printf("It's Tuesday.\n");
            break;
        case 3:
            printf("It's Wednesday.\n");
            break;
        case 4:
            printf("It's Thursday.\n");
            break;
        case 5:
            printf("It's Friday! The weekend is near! 🎉\n");
            break;
        case 6:
        case 7: // Multiple cases can share the same code block
            printf("It's the weekend! (Saturday or Sunday) 🌴\n");
            break;
        default: // Executed if none of the case values match
            printf("Invalid day number. Please enter a number between 1 and 7.\n");
            break;
    }

    return 0;
}