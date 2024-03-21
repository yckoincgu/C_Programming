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
	return 0;
}
