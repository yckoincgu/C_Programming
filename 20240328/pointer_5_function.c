#include <stdio.h>
#include <stdlib.h>
const int arrayDelimiter=3;
	
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
	int i;
	printf("check array length one by one: ");
	for (i=0; i< sizeof(yarray)-arrayDelimiter; i++) 
		printf("%d, ", yarray[i]);
	printf("\n");
	printf("The array length is ");
	return (int)sizeof(yarray)-arrayDelimiter;
}

