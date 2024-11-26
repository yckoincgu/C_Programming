extern int a=10;
static int b=10;

#include <stdio.h>

void aTest(){
	b=5;
	a=5;
		
	printf("in function aTest a= %d\n", a);	// it does not have the same location as extern a
	printf("in function aTest b= %d\n", b);	// it does not have the same location as static b
	printf("in function aTest the address of a= %p\n", &a);	
	printf("in function aTest the address of b= %p\n", &b);		
}

int main ()
{
	
	printf("in main function  a= %d\n", a);	// it does not have the same location as extern a
	printf("in main function  b= %d\n", b);	// it does not have the same location as static b
	printf("in main function  the address of a= %p\n", &a);	
	printf("in main function  the address of b= %p\n", &b);		
	aTest();

return 0;
}
