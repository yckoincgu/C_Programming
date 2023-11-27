#include <stdio.h>
int a=20;				// it does not have the same location as main() a
static int b=20;		// it does not have the same location as main() b

int main ()
{
	
	printf("%p\n", &a);
	printf("%p\n", &b);

	static int a;
	int b;
	printf("%p\n", &a);
	printf("%p\n", &b);

return 0;
}


