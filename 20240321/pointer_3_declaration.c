#include <stdio.h>
#include <stdlib.h>

struct Person {
	int id;
	float num2;
};

int main(void)
{
	int c, d;
	int *ptrInt;
	struct Person b11255001;
	struct Person *ptr;
	c = 10;
	ptrInt = &c; 	/* ptrInt points to c */
	d = *ptrInt; 	/* d is assigned the value to which ptrInt points, 10 */
	ptrInt = &d; 	/* now points to d */
	*ptrInt = 12; 	/* d is now 12 */
	printf("the ptrInt value is %d \n", *ptrInt);
	
	ptr = &b11255001;
	(*ptr).id = 3; 		/* assigns 3 to the id of b11255001 */
	ptr->num2 = 44.3; 	/* assigns 44.3 to the num2 of b11255001 */
	*ptrInt = ptr->id; 	/* eqivalent to d = b11255001.id; */
	return 0;
}
