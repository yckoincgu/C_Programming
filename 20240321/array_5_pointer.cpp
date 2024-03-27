#include <stdio.h>
#include <stdlib.h>

struct Student {
	int id;
	float height;
};

struct Student ourStudent[4];
#define Student_SIZE (sizeof(ourStudent)/sizeof(*ourStudent))

int main(void)
{
	
	printf("the Student_SIZE is %d \n", Student_SIZE);
	struct Student *ptr=&ourStudent[0];  // or *ptr=ourStudent;
	ptr->id=100;
	ptr++;
	ptr->id=200;
	int i;
	
	for (i=0; i<Student_SIZE; i++) {
		printf("the Student id is %d \n", ourStudent[i].id);
	}
	
	return 0;
}
