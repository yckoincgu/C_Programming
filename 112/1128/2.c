

#include <stdio.h>
int main ()
  
{
	int a=5;
	printf("vaiable a value = %d\n", a);
	printf("The address of variable =  %p\n", &a);
	
	int *p=&a;
	printf("\nThe value of *p = %d", *p);
	printf("\nThe address of *p = %p\n", p);
	printf("\n");


	int b=5, c=5;
	printf("The address of b when int b=5:  %p\n", &b);
	printf("The address of c when int c=5:  %p\n", &c);	


	b=c;
	printf("After assignment of b=c, the address of b = %p\n", &b);
	printf("After assignment of b=c, the address of c = %p\n", &c);	

	

return 0;
}
