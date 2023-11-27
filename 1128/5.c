#include <stdio.h>
extern int b=20;	// it does not have the same location as main() b

int main ()
{


	printf("%p\n", &b);		
	

	int b;
	

	printf("%p\n", &b);		
	


return 0;
}


