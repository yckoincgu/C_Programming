#include <stdio.h>
#include <stdlib.h>

struct Student {
	int id;
	char *name;
};

struct Student S1, S2, S3, S4;


struct Student *who( int b )
{
	struct Student *studentAddress;

	if (b == 1) 	studentAddress = &S1;
	else if (b==2) 	studentAddress = &S2;
	else if (b==3) 	studentAddress = &S3;
	else studentAddress = &S4;
	
	printf("\n");
	return studentAddress;
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
