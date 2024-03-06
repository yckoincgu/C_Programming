#include <stdio.h>

int main(void)
{
	float pi = 3.141592;
	int truncated_pi = (int)pi; // truncated_pi == 3
	// An example of casting a char as an int:
	char my_char = 'A';
	int my_int = (int)my_char; // my_int == 65, which is the ASCII value of 'A'
	printf("my_int = %d\n", my_int);
	return 0;
}

