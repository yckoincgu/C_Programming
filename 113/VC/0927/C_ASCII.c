#include <stdio.h>
int main()
{
	int a[5], i;
	a[0]=65;
	a[1]=66;
	a[2]=67;
	a[3]=68;
	a[4]=69;
	
	for(i=0;i<5;i++)
		printf(" %c",a[i]);
	
	printf("\n");
	return 0;
}