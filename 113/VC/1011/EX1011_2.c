#include <stdio.h>


int main(void) {
	int a[5], i;
	a[0]=65;
	a[1]=66;
	a[2]=67;
	a[3]=68;
	a[4]=69;

	for(i=4;i>-1;i--)
		printf(" %c",a[i]);
    printf("\n");

	for(i=2;i>0;i--)
		printf(" %c",a[i]);
    printf("\n");

	return 0;
}
