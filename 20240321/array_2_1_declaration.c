#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char ystring[] = 	"This is a very, very long "
						"string that requires two lines.";
	printf("the ystring[] contains\n");
	for (i=0; i< sizeof(ystring); i++) {
		printf("%c", ystring[i]);
	}	
	
	return 0;
}
