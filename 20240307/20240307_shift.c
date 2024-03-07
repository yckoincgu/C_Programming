#include <stdio.h>

int main(void)
{

    int x = 16; // Binary representation: 00000000 00000000 00000000 00010000
    int result = x >> 2; // Right shift by 2 positions

    printf("Original value x : %d\n", x);
    printf("Result x after right shift: %d\n", result);
    
    int y = 16; // Binary representation: 00000000 00000000 00000000 00010000
    result = y << 2; // Right shift by 2 positions

    printf("Original value y : %d\n", y);
    printf("Result y after right shift: %d\n", result); 
	   
	y = 2 | 3;	// or operator
	printf("y= %d\n", y); 
	y = 2 & 3;	// and operator
	printf("y= %d\n", y); 	
	
    return 0;

}

