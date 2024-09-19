#include <stdio.h>
int main ()
{
	int a[3];
	
	printf("%p\n", &a);
	printf("%p\n", &a[0]);
	printf("%p\n", &a[1]);
	printf("%p\n", &a[2]);

return 0;
}
