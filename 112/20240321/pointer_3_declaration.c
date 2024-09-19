#include <stdio.h>
#include <stdlib.h>

struct Student {
	int id;
	float height;
};

int main(void)
{
	int c, d;
	int *ptrInt;
	
	struct Student b11255001;
	struct Student *ptr;
	
	
	ptr = &b11255001;
	(*ptr).id = 3; 		/* (*ptr).id  */
	printf("the ptr pointer value of (*ptr).id is %d \n", *ptr);	
	
	ptr->height = 44.3; /* assigns 44.3 to the height of b11255001 */
	printf("the ptr pointer value of ptr->height is %d \n", *ptr);	
	
	*ptrInt = ptr->id; 	/* eqivalent to d = b11255001.id; */
	printf("*ptrInt = %d", *ptrInt);
	return 0;
}
