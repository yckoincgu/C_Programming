#include <stdio.h>

#define ROWS 4
#define COLS 3

void alignDecimals(float arr[ROWS][COLS], int rows, int cols) {
    int maxDecimalPos[COLS];

    // Initialize maxDecimalPos array
    for (int j = 0; j < cols; j++) {
        maxDecimalPos[j] = 0;
    }

    // Find the maximum number of digits before the decimal point in each column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int integerPart = (int)arr[i][j];
            int digitsBeforeDecimal = 0;
            while (integerPart != 0) {
                integerPart /= 10;
                digitsBeforeDecimal++;
            }
            if (digitsBeforeDecimal > maxDecimalPos[j]) {
                maxDecimalPos[j] = digitsBeforeDecimal;
            }
        }
    }

    // Print each line with right alignment
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%*.*f ", maxDecimalPos[j] + 3, 2, arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float arr[ROWS][COLS] = {
        {123.45, 67.89, 1.234},
        {4567.8, 123.4, 56.789},
        {12.3, 456.78, 9.01},
        {0.123, 45.678, 1234.5}
    };

    alignDecimals(arr, ROWS, COLS);

    return 0;
}
