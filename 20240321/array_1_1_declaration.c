#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i;

	short anArray[]= { 3, 6, 9, 12, 15 };
	for (i=0; i< (sizeof(anArray)/sizeof(short)); i++) {
		printf("By array, the anArray contains %d \n", anArray[i]);
	}
	// short *ptrOneDimension=anArray;  This statement is correct.
	short *ptrOneDimension;
	ptrOneDimension=anArray;
	for (i=0; i< (sizeof(anArray)/sizeof(short)); i++, ptrOneDimension++) {
		printf("By pointer, the anArray contains %d \n", *ptrOneDimension);
	}	
	
	
	int twoDimensionArray[2][3] = {	{ 5, 2, 1 },
						            { 6, 7, 8 }
					              };
			              
	int j;
	printf("By array, the twoDimensionArray contains\n");
	for (i=0; i< 2; i++) {
		for(j=0; j<3; j++)
			printf("%d, ", twoDimensionArray[i][j]);
		printf("\n");	
	}		
	
	int *ptrTwoDimension=twoDimensionArray;	
	printf("by pointer \n");
	const int col=3;			  
	for (i=0; i< 2; i++) {
		for(j=0; j<col; j++)
			printf("%d, ", *((ptrTwoDimension+i*col)+j));
		printf("\n");	
	}						  
	
	return 0;
}
