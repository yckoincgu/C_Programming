#include <stdio.h>
#include <stdlib.h>

const int stringDelimiter=3;

int main(void)
{
	char *ptr; 	// Declaration of an integer pointer
				// 1. *  is the deferencing operator
				// 2. ptr is an address, i.e. the pointed address
	 			
	char 	stringArray[]="abc";	// stringArray is the address of this array
	
	ptr = stringArray;	// stringArray is the address of an array
	printf("the pointed character is %c \n", *ptr); // *ptr = 'a';
	
	printf("To print the pointed string, a loop is necessary for pointer \n");
	int i;
	for (i=0; i< sizeof(ptr)-stringDelimiter; i++) 
		printf("%c", ptr[i]);	
	printf("\n");  
	  
	printf("To print an array 'abc', the format \%\\s is necessary %s \n", stringArray); 
	ptr++;
	*ptr='x';		
	printf("the stringArray after modification is %s \n", stringArray); 		
		
				
	return 0;
}
