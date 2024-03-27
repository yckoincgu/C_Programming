#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *ptr; 	// Declaration of an integer pointer
				// 1. *  is the deferencing operator
				// 2. value = *ptr;
		  		// 3. In C, assigning an integer value directly to a pointer is generally not recommended
	 			//    as it can lead to unexpected behavior and errors
	 			
	char 	stringArray[]="abc";
	
	ptr = stringArray;
	printf("the pointed character is %c \n", *ptr); // *ptr = 'a';   
	printf("the stringArray is %s \n", stringArray); 
	ptr++;
	*ptr='x';		
	printf("the stringArray after modification is %s \n", stringArray); 		
		
				
	return 0;
}
