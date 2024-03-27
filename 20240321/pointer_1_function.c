#include <stdio.h>
#include <stdlib.h>

char S1[]="peter", S2[]="john", S3[]="mary", S4[]="eric";
const int stringDelimiter=3;	// '\0': 3 characters

char *who( int b )
{
	char *returnAddress;

	if (b == 1) 	returnAddress = S1;
	else if (b==2) 	returnAddress = S2;
	else if (b==3) 	returnAddress = S3;
	else returnAddress = S4;
	
	int i;
	printf("In sub function \n");
	printf("who string is \n");
	for (i=0; i< sizeof(returnAddress)-stringDelimiter; i++) {
		printf("%c", returnAddress[i]);
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
	for (i=0; i< sizeof(student)-stringDelimiter; i++) {
		printf("%c", student[i]);
	}	
	return 0;
}
