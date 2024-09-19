#include <stdio.h>
int a=20;			// it has the same location as extern a

int main ()
{

	printf("%p\n", &a);	
	
	
	extern int a;

	printf("%p\n", &a);
	


return 0;
}

