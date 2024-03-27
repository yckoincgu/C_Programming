#include <stdio.h>
#include <stdlib.h>
/* 
	'\0': string delimiter in C language 
*/

int main(void)
{
	char string[] = "Merkkijono";
	int i;
	printf("the string[] = 'Merkkijono' contains\n");
	for (i=0; i< sizeof(string); i++) {
		printf("%c", string[i]);
	}				  
	printf("\nthe xstring[] = {'M', 'e', 'r', 'k', 'k', 'i', 'j', 'o', 'n', 'o', '\\0'} \n");
	printf("contains \n");				  
	char xstring[] = {'M', 'e', 'r', 'k', 'k', 'i', 'j', 'o', 'n', 'o', '\0'};
	for (i=0; i< sizeof(xstring); i++) {
		printf("%c", xstring[i]);
	}
	printf("\n");
	char ystring[] = 	"This is a very, very long "
						"string that requires two lines.";
	printf("the ystring[] contains\n");
	for (i=0; i< sizeof(ystring); i++) {
		printf("%c", ystring[i]);
	}	
	
	return 0;
}
