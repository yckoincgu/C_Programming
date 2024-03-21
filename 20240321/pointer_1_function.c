#include <stdio.h>
#include <stdlib.h>

char S1[]="peter", S2[]="john", S3[]="mary", S4[]="eric";
const int stringDelimiter=3;

char *who( int b )
{
	char *myReturn;

	if (b == 1) 	myReturn = S1;
	else if (b==2) 	myReturn = S2;
	else if (b==3) 	myReturn = S3;
	else myReturn = S4;
	
	int i;
	
	for (i=0; i< sizeof(myReturn)-stringDelimiter; i++) {
		printf("%c", myReturn[i]);
	}
	printf("\n");
	return myReturn;
}




int main(void)
{
	char *student;
	int j;
	
	printf("who string is \n");
	student = who( 3 ); /* pointer returned from a function. */
	for (j=0; j< sizeof(student)-stringDelimiter; j++) {
		printf("%c", student[j]);
	}	
	return 0;
}
