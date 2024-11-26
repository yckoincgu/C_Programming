#include <stdio.h>

void aTest(){
	static int b=10;
	b += 10;
	printf("%d\n", b);	
}

int main ()
{
	aTest();
	aTest();
	return 0;
}



