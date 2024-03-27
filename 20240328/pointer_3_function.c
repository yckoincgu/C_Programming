#include <stdio.h>
#include <string.h>

struct Student {
	int id;
	char *name;
};
	
int assignStudentId(struct Student *studentAddress);

int main(void)
{
	struct Student S1, S2, S3, S4;

	S1.name="peter";
	S2.name="john";
	S3.name="mary";
	S4.name="eric";
	
	printf("check S2 by function then assign id with ");
	if(assignStudentId( &S2 ))  /* pointer returned from a function. */
		printf("%d", S2.id);
	else printf("This assignment failed.");	
	return 0;
}

int assignStudentId(struct Student *studentAddress)
{
	int flag=1;
	// strcmp: if equal then return 0
	if (strcmp(studentAddress->name,"Peter")==0) studentAddress->id = 10;
	else if (strcmp(studentAddress->name,"john")==0) studentAddress->id = 20;
	else if (strcmp(studentAddress->name,"mary")==0) studentAddress->id = 30;
	else if (strcmp(studentAddress->name,"eric")==0) studentAddress->id = 40;
	else flag=0;
	return flag;
}

