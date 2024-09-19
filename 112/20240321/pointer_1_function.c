#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S1[]="peter", S2[]="john", S3[]="mary", S4[]="eric";

char *who( int b )
{
	char *returnAddress, *tempAddress;

	if (b == 1) 	returnAddress = S1;
	else if (b==2) 	returnAddress = S2;
	else if (b==3) 	returnAddress = S3;
	else returnAddress = S4;
	
	int i;
	printf("In sub function \n");
	printf("who string is \n");
	i=0;
	tempAddress=returnAddress;
	while ((int)*tempAddress != 0) {  // '\0' ASCII value =0; 
		printf("%c", *tempAddress);
		tempAddress++;
		i++;
	}
	printf("\n");
	return returnAddress;
}




int main(void)
{
	char *student;
	int i;
	
	
	student = who( 3 ); /* pointer returned from a function. */
	printf("In the calling function \n");
	
	while ((int)*student != 0) {  // '\0' ASCII value =0; 
		printf("%c", *student);
		student++;
		i++;
	}	
	return 0;
}
