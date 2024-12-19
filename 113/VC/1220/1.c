#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_SUCCESS 0
#define NAN -1


int getNumber(void) {
    long int inputNum;
    char inputNumString[100]; // Adjust size as needed
    int validInput = 0;

    while (!validInput) {
        printf("Enter an integer number: ");

        // Read the entire line using fgets to handle potential spaces
        if (fgets(inputNumString, sizeof(inputNumString), stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            return NAN; // Or handle error differently
        }

        // Remove trailing newline (if present)
        size_t len = strlen(inputNumString);
        if (len > 0 && inputNumString[len - 1] == '\n') {
            inputNumString[len - 1] = '\0';
        }

        // Check if the input contains only digits, a decimal point, or a minus sign
        validInput = 1;
        for (int i = 0; inputNumString[i] != '\0'; i++) {
            if (!isdigit(inputNumString[i]) && inputNumString[i] != '.' && inputNumString[i] != '-') {
                validInput = 0;
                break;
            }
        }

        if (!validInput) {
            printf("Invalid input. Please enter a number.\n");
        } else {
            // Attempt conversion using strtod for better error handling
            char *endptr;
            inputNum = strtol(inputNumString, &endptr,10);

            // Check if conversion was successful (endptr points to the end of the valid number)
            if (*endptr != '\0') {
                validInput = 0;
                printf("Invalid input. Please enter a number.\n");
            }
        }
    }

    return inputNum;
}

void bPrint(int *bits, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

void printBinary(int n){
	int bits[32];
	int  i, m;
	int  switchflag;

    for(i=31; i>=0; i--){bits[i]= n % 2; n=n/2;}
        bPrint(bits, 32);    

}    

int main(void) {
    int number = getNumber();
    printf("You entered: %10d\n", number);
    printf("Its binary code is ");
    printBinary(number);


    return 0;
}