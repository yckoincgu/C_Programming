#include <stdio.h>

/*
	restrict: the object pointed to by that pointer will only be accessed 
	through that pointer for the duration of its scope
*/ 
char *xstrcpy(char *s1, char *s2)
{
	char *dst = s1;
	char *src = s2;
	/* Do the copying in a loop. */
	while ((*dst++ = *src++) != '\0');
	*dst='\0';
	
	/* The body of this loop is left empty. */
	/* Return the destination string. */
	return s1;
}


int main(void)
{
	char sourceStr[]="test";
	char destinationStr[sizeof(sourceStr)/sizeof(*sourceStr)];
	
	
	char *ptr=xstrcpy(destinationStr,sourceStr);
	while (*ptr != '\0') printf("%c", *ptr++);
}
