#include <stdio.h> 	/* for fprintf and stderr */

int main(void)
{
	/* this is a 'C block' */
	int i = 5;	// black i
	{
		/* this is also a 'block', 
		 1. containing executable statements
		 2. the scope of declaration
		    ex. a variable declared in this block
			    its activity is limited in this block
				outside this block, the variable is NOT available 
		 3. block can be nested, i.e. there are blocks inside the outer block 
		
		*/
		printf("before inner i is declared the black i = %d\n", i);
		int i = 6;	// red i
		printf("After inner i is declared the red i = %d\n", i);
	}
	printf("outsider i = %d\n", i);
	return 0;
}
