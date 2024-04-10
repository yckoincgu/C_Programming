#include <stdio.h>

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

char *xstrcat(char *x, char *s1, char *s2)
{
	char *ptr=xstrcpy(x,s1);
	
	while(*ptr != '\0') ptr++;
	ptr=xstrcpy(ptr,s2);
	return x;
}


int main(void)
{
	char s1[]="AAA", s2[]="BBB";
	char x[sizeof(s1)/sizeof(*s1)+sizeof(s2)/sizeof(*s2)-1];
	
	char *ptr=xstrcat(x,s1,s2);
	while (*ptr != '\0') printf("%c", *ptr++);
}
