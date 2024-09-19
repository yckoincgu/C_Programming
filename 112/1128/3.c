
extern int a=10;
static int b=10;


#include <stdio.h>

void aTest(){
	
	printf("%d\n", b);
	printf("%d\n", a);
		
}

int main ()
  
{

	int b=5;
	int a=5;
	
	printf("%d\n", b);
	printf("%d\n", a);
	aTest();

return 0;
}



