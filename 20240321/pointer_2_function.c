#include <stdio.h>
#include <stdlib.h>

struct Student {
	int id;
	char *name;
};

struct Student S1, S2, S3, S4;


struct Student *who( int b )
{
	struct Student *returnStudent;

	if (b == 1) 	returnStudent = &S1;
	else if (b==2) 	returnStudent = &S2;
	else if (b==3) 	returnStudent = &S3;
	else returnStudent = &S4;
	
	printf("\n");
	return returnStudent;
}




int main(void)
{

	S1.name="peter";
	S2.name="john";
	S3.name="mary";
	S4.name="eric";
	
	
	
	printf("who name is \n");
	struct Student *s = who( 3 ); /* pointer returned from a function. */
	printf("%s", s->name);
	return 0;
}
