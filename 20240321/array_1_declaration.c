#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int numbers[6];
	int i;
	
	int point[6]={0,0,1,0,0,0};
	//int point[]={0,0,1,0,0,0};		not available in C but available in C++
	
	int copyValuesInArray[20]={245};	// cannot copy 245 with 20 times
	for(i=0; i<6; i++){
		printf("the copyValuesInArray contains %d \n", copyValuesInArray[i]);
	}
	
	char letters[6]={0,0,1,0,0,0};	// compiler may not complain
	
	short anArray[]= { 3, 6, 9, 12, 15 };
	for (i=0; i< (sizeof(anArray)/sizeof(short)); i++) {
		printf("the anArray contains %d \n", anArray[i]);
	}
	
	int two_d[2][3] = {	{ 5, 2, 1 },
						{ 6, 7, 8 }
					  };
	int j;
	printf("the two_d contains\n");
	for (i=0; i< 2; i++) {
		for(j=0; j<3; j++)
			printf("%d, ", two_d[i][j]);
		printf("\n");	
	}				  
					  
	
	return 0;
}
