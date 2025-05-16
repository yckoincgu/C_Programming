#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int binToSignedDec(const char* bin) {
    int dec = 0;
    int len = strlen(bin);

    if (bin[0] == '1') { 
        
        for (int i = 1; i < len; i++) {
            if (bin[i] == '1') {
                dec += pow(2, len - 1 - i);
            }
        }
        dec += pow(2, len - 1);  
        dec = -((1 << len) - dec);  
    } else {
        for (int i = 0; i < len; i++) {
            if (bin[i] == '1') {
                dec += pow(2, len - 1 - i);
            }
        }
    }

    return dec;
}

int main() {
    int n = 5;
    char* binary = (char*)malloc(9);
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (n % 2) + '0';
        n /= 2;
    }
    binary[8] = '\0';
    printf("二進位: %s\n", binary);

    
    int len = strlen(binary);
    int firstOne = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            firstOne = i;
            break;
        }
    }

    if (firstOne != -1) {
        for (int i = 0; i < firstOne; i++) {
            binary[i] = (binary[i] == '0' ? '1' : '0');
        }
    }

    int complement = binToSignedDec(binary);
    free(binary);

    printf("數字: %d\n", 5);
    printf("其 2's complement : %d\n", complement);

    return 0;
}






























