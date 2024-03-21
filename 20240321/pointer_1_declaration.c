#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr; 	// Declaration of an integer pointer
				// 1. *  is the deferencing operator
				// 2. value = *ptr;
		  		
	*ptr = 2; 	// 3. In C, assigning an integer value directly to a pointer is generally not recommended
	 			//    as it can lead to unexpected behavior and errors
	 			// *ptr = (int) 2;   no good	
	printf("the ptr pointer value by assigning integer directly is %d \n", *ptr);	
		
	int num=10, i=5;
	ptr= &num;
	printf("the ptr pointer value is %d \n", *ptr);			
			// 4. the address operator '&': int *ptr = &num;
			//    Pointer ptr now holds the address of the variable num
				
	ptr = NULL; // 5. Assigning NULL to ptr
	
	// 6. Allocating memory for an integer array
	int *dynamicArray = (int*)malloc(5 * sizeof(int)); 
	printf("the dynamicArray address is %p \n", dynamicArray);	
			
	for(i=0; i<5; i++, dynamicArray++, num++){
		// 6. dynamicArray++; Moves dynamicArray to the next memory location of the same data type
		dynamicArray=&num;
		printf("the dynamicArray value in array are %d \n", *dynamicArray);
	}
				
	free(dynamicArray);			
				
	return 0;
}
