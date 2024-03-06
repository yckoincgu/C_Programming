/* this is a 'global' variable, it can be accessed from anywhere in the program */
int i = 5; 

int main(void)
{
	/* this is a function, all variables inside of it are "local" to the function. */
	int i = 6; 	/* 'i' now equals 6 */
	printf("%d\n", i); /* prints a '6' to the screen, instead of the global variable of 'i', which is 5 */
	return 0;
}

