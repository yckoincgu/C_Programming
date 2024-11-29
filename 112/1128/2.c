

#include <stdio.h>
int main ()
  
{
	int a=5;
	printf("variable a's value = %d\n", a);
	printf("The address of variable, &a =  %p\n", &a);
	
	int *p;  // int *p=&a;
	p=&a;
	printf("\nAssign the address of a into p", *p);
	printf("\nThe address of p = &a = %p\n", p);
	printf("Get the value of *p = %d\n", *p);
	printf("\n");

	printf("\nChange the value of variable a by address p, *p=10; \n");
	*p=10;
	printf("the variable a's value = %d\n\n", a);


	int b=5, c=5;
	printf("The address of b when int b=5:  %p\n", &b);
	printf("The address of c when int c=5:  %p\n", &c);	


	b=c;
	printf("After assignment of b=c, the address of b = %p\n", &b);
	printf("After assignment of b=c, the address of c = %p\n", &c);	

	

return 0;
}
