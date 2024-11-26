#include <stdio.h>
int main ()
{
	char a='K';
	char b=*(&a);
	char *const x=&a;

	
	printf("%c\n", a);
	printf("%c\n", b);
	printf("%c\n", *x);	
	
	printf("a address %p\n", &a);
	printf("%p\n", &b);	
	printf("x address %p\n", &x);	


return 0;
}
