#include <stdio.h>

void printBinary(short int n, int bitsize) {
	int i;
	int bit;
			
	for (i = bitsize - 1; i >= 0; i--) {
		// 1. Right shift (n >> i) moves the i-th bit to the LSB position.
		// 2. Bitwise AND (& 1) checks if that LSB is 1 or 0.
		bit = (n >> i) & 1;
		printf("%d", bit);
	}
	printf("\n");
}



int main (){
	short int ubits=-10;
	printBinary(ubits, sizeof(ubits) * 8);
	return 0;
}