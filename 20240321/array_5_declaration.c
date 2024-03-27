#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	float A[2][2];
	float *pf;
	pf = &A[0][0];
	*(pf+1) = 1.3; /* assigns 1.3 to A[0][1] */
	*(pf+2) = 2.3; /* assigns 2.3 to A[1][0] */
	int i,j;

	printf("Pointer array can be assigned, For example: \n");
	for (i=0; i< 2; i++) {
		for (j=0; j< 2; j++)
			printf("%f ,", A[i][j]);
		printf("\n");	
	}
	
	return 0;
}
