#include <stdio.h>

/*
	restrict: the object pointed to by that pointer will only be accessed 
	through that pointer for the duration of its scope
*/ 
char *xstrcpy(char *s1, char *s2)
{
	char *dst = s1;
	const char *src = s2;
	/* Do the copying in a loop. */
	while ((*dst++ = *src++) != '\0');
	*dst='\0';
	
	/* The body of this loop is left empty. */
	/* Return the destination string. */
	return s1;
}


int main(void)
{
	char s[]="test";
	char x[sizeof(s)/sizeof(*s)];
	
	
	char *ptr=xstrcpy(x,s);
	while (*ptr != '\0') printf("%c", *ptr++);
}
