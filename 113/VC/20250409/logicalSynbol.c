#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Logical_AND_Symbol_Pointer = L"\u2227";
char *Logical_AND_code = "\\u2227";
char *Logical_OR_Symbol_Pointer = L"\u2228";
char *Logical_OR_code = "\\u2228";
char *Logical_NOT_Symbol_Pointer = L"\u00AC";
char *Logical_NOT_code = "\\u00AC";
char *Logical_Implication_Symbol_Pointer = L"\u2192";
char *Logical_Implication_code = "\\u2192";
char *Logical_Equivalence_Symbol_Pointer = L"\u2194";
char *Logical_Equivalence_code = "\\u2194";
char *Logical_All_Symbol_Pointer = L"\u2200";
char *Logical_All_code = "\\u2200";
char *Logical_Exists_Symbol_Pointer = L"\u2203";
char *Logical_Exists_code = "\\u2203";
char *Logical_Therefore_Symbol_Pointer = L"\u2234";
char *Logical_Therefore_code = "\\u2234";
char *Logical_Because_Symbol_Pointer = L"\u2235";
char *Logical_Because_code = "\\u2235";
char *inputStringDynamic = NULL;

void freeInputStrings() {
    free(inputStringDynamic); // Free the dynamically allocated memory
    printf("The allocated memory for input is freed already \n");
}

void clearScreen() {
    system("clear");
}

int getWordLength(char *s) {
    char *ptr = s, space = (int)32;
    int i = 0;
    while (*ptr != '\0' && *ptr != space) {
        ptr++;
        i++;
    }
    return i;
}
// Function to convert Unicode escape sequence to wide character
wchar_t unicode_to_wchar(const char *unicode_escape) {
    if (unicode_escape == NULL || strlen(unicode_escape) != 6 || strncmp(unicode_escape, "\\u", 2) != 0) {
        return 0; // Invalid input
    }
    
    wchar_t result = 0;
    for (int i = 2; i < 6; i++) {
        int digitValue;
        if (unicode_escape[i] >= '0' && unicode_escape[i] <= '9') {
            digitValue = unicode_escape[i] - '0';
        } else if (unicode_escape[i] >= 'a' && unicode_escape[i] <= 'f') {
            digitValue = unicode_escape[i] - 'a' + 10;
        } else if (unicode_escape[i] >= 'A' && unicode_escape[i] <= 'F') {
            digitValue = unicode_escape[i] - 'A' + 10;
        } else {
            return 0; // Invalid hex digit
        }
        result = (result << 4) | digitValue;
    }
    return result;
}

void printLogicExpression(char *s, int strLength) {
    char *ptr = s;
    int wordLength = 0;
    int startPosition = 0; // Changed to 0-based indexing.
    char tmpArray[20];
    printf("\n starting analysis\n");

    while (startPosition < strLength) { // Changed loop condition.
        wordLength = getWordLength(ptr);
        if (wordLength > 0) {
            strncpy(tmpArray, ptr, wordLength);
            tmpArray[wordLength] = '\0';

            if (strncmp(tmpArray, "\\u", 2) == 0) {
                wchar_t wch = unicode_to_wchar(tmpArray);
                if (wch != 0) {
                    printf("test %lc\n", wch); // Use %lc for wide characters.
                } else {
                    printf("test %s\n", tmpArray);
                }

            } else {
                printf("test %s\n", tmpArray);
            }
        }
        ptr += wordLength + 1;         // Move pointer, handle spaces
        startPosition += wordLength + 1; // Update start position
        if (startPosition < strLength && s[startPosition] == ' ')
            startPosition++;
    }
    printf("\n");
}


int getInputAndSetToHeap() {
    // Dynamic allocation example
    int successFlag = 1;
    size_t bufferSize = 0;

    if (getline(&inputStringDynamic, &bufferSize, stdin) != -1) {
        // Remove trailing newline character, if present
        char *newlineChar = strchr(inputStringDynamic, '\n');
        if (newlineChar != NULL) {
            *newlineChar = '\0'; // null-terminated character for C string
        }
        int stringLength = strlen(inputStringDynamic);
        printLogicExpression(inputStringDynamic, stringLength);

        printf("Analysis of your input is presented below\n");
        printf("The length of %s is %d \n", inputStringDynamic, stringLength);
        int i = 0;
        for (i = 0; i < stringLength; i++) {
            if (!(inputStringDynamic[i] >= '0' && inputStringDynamic[i] <= '9')) {
                successFlag = 0;
                printf("%c is an error digit \n", inputStringDynamic[i]);
            } else
                printf("%c\n", inputStringDynamic[i]);
        }
    } else {
        printf("Error reading input.\n");
        successFlag = 0;
    }
    return successFlag;
}

void operatorTable(char *operatorName, char *operatorSymbol_Pointer, char *operatorCode, int strLength) {
    printf("%-25s %-17s %12s %15d \n", operatorName, operatorSymbol_Pointer, operatorCode, strLength);
}

void displayMenu() {
    clearScreen();
    printf("Logical atom like p, q, r, s, t, and so on \n");
    printf("%-20s %-20s %-20s %10s\n", "Operator Name ", "Symbol_Pointer", "Pointer Code", "string length");
    operatorTable("Logical AND", Logical_AND_Symbol_Pointer, Logical_AND_code, strlen((char *)Logical_AND_Symbol_Pointer));
    operatorTable("Logical OR", Logical_OR_Symbol_Pointer, Logical_OR_code, strlen((char *)Logical_OR_Symbol_Pointer));
    operatorTable("Logical NOT", Logical_NOT_Symbol_Pointer, Logical_NOT_code, strlen((char *)Logical_NOT_Symbol_Pointer));
    operatorTable("Logical Implication", Logical_Implication_Symbol_Pointer, Logical_Implication_code, strlen((char *)Logical_Implication_Symbol_Pointer));
    operatorTable("Logical Equivalence", Logical_Equivalence_Symbol_Pointer, Logical_Equivalence_code, strlen((char *)Logical_Equivalence_Symbol_Pointer));
    operatorTable("Logical All", Logical_All_Symbol_Pointer, Logical_All_code, strlen((char *)Logical_All_Symbol_Pointer));
    operatorTable("Logical Exists", Logical_Exists_Symbol_Pointer, Logical_Exists_code, strlen((char *)Logical_Exists_Symbol_Pointer));
    operatorTable("Logical Therefore", Logical_Therefore_Symbol_Pointer, Logical_Therefore_code, strlen((char *)Logical_Therefore_Symbol_Pointer));
    operatorTable("Logical Because", Logical_Because_Symbol_Pointer, Logical_Because_code, strlen((char *)Logical_Because_Symbol_Pointer));
    printf("LeftParentheses:  ( \n");
    printf("RightParentheses: ) \n");
    printf("Logical statements: P, Q, R, T \n");
    printf("\n");

    printf("Please enter your logical expression below \n");
    getInputAndSetToHeap();
}

int main() {
    setlocale(LC_ALL, "");
    displayMenu();
    int inputInt = 0;
    if (getInputAndSetToHeap() > 0) { // if succeed
        inputInt = atoi(inputStringDynamic);
        // printBinary(inputInt);  // Presuming this function is defined
    }
    freeInputStrings();
    return 0;
}

