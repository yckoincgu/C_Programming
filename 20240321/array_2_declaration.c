#include <stdio.h>
#include <stdlib.h>
/* 
	'\0': string delimiter in C language 
*/

static const char myFlower[] = { 'P', 'e', 't', 'u', 'n', 'i', 'a', '\0' };
static const char *myColors[] 
= {"Red", "Orange", "Yellow", "Green", "Blue", "Violet" };

int main(void)
{
	int i;
	for (i=0; i< sizeof(myFlower); i++) {
		printf("%c", myFlower[i]);
	}
	printf("\n");

	for (i=0; i< sizeof(myColors)/sizeof(*myColors); i++) {
		printf("%s, ", myColors[i]);
	}	
	
	return 0;
}
