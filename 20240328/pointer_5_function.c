#include <stdio.h>
#include <stdlib.h>
	
int getArrayLength(int *yarray);

int main(void)
{
	int S1[4]={0,1,2,3}, 
		S2[5]={0,1,2,3,4}, 
		S3[6]={0,1,2,3,4,5}, 
		S4[7]={0,1,2,3,4,5,6};

	printf("%d", getArrayLength( S2 ));
	
	return 0;
}

int getArrayLength(int *yarray)
{
	// In C, there isn't a specific delimiter for integer arrays 
	// like the null character '\0' for strings. 
	return 0;
}

