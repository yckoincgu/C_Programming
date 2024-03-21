#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	float A[2][2];

	int i,j;
	
	
	A[0][0] = 3.66f; /* assigns 3.66 to linearA[17]; */
	A[0][1] = 1.44f; /* refers to linearA[12];*/
	printf("array can be assigned directly, For example: \n");
	for (i=0; i< 2; i++) {
		for (j=0; j< 2; j++)
			printf("%f ,", A[i][j]);
		printf("\n");	
	}
	
	return 0;
}
