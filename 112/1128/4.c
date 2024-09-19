extern int a=10;
static int b=10;

#include <stdio.h>

void aTest(){
	b=5;
	a=5;
		
	printf("%d\n", a);	// it does not have the same location as extern a
	printf("%d\n", b);	// it does not have the same location as static b
	printf("%p\n", &a);	
	printf("%p\n", &b);		
}

int main ()
{
	
	printf("%d\n", a);	// it does not have the same location as extern a
	printf("%d\n", b);	// it does not have the same location as static b

	printf("%p\n", &a);	
	printf("%p\n", &b);	
	aTest();

return 0;
}
