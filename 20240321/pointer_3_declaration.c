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
	
	c = 10;
	ptrInt = &c; 	/* ptrInt points to c */
	d = *ptrInt; 	/* d is assigned the value to which ptrInt points, 10 */
	ptrInt = &d; 	/* now points to d */
	*ptrInt = 12; 	/* d is now 12; not recommended */
	printf("the ptrInt value is %d \n", *ptrInt);
	
	ptr = &b11255001;
	(*ptr).id = 3; 		/* (*ptr).id  */
	printf("the ptr pointer value of (*ptr).id is %d \n", *ptr);	
	
	ptr->height = 44.3; /* assigns 44.3 to the height of b11255001 */
	printf("the ptr pointer value of ptr->height is %d \n", *ptr);	
	
	*ptrInt = ptr->id; 	/* eqivalent to d = b11255001.id; */
	return 0;
}
