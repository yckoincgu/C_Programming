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

char *(xstrAdd)(char *str_1, char *str_2)
{
	char *appenedStr = str_1;
	/* Move s so that it points to the end of str_1. */
	while (*appenedStr != '\0') appenedStr++;
	
	/* Copy the contents of str_2 into the space at the end of str_1. */
	appenedStr=xstrcpy(appenedStr, str_2);
	return str_1;
}

char *xstrCat(char *newSpace, char *s1, char *s2){
	char *ptr=xstrAdd(newSpace, s1);
		  ptr=xstrAdd(ptr, s2);
	return ptr;	
}


int main(void)
{
	char s1[]="AAA";
	char s2[]="BBB";
	char newSpace[sizeof(s1)/sizeof(*s1)+sizeof(s2)/sizeof(*s2)-1]=xstrCat(newSpace, s1,s2);

	char *ptr=newSpace;
	printf("The concated string is ");
	while (*ptr != '\0') printf("%c", *ptr++);
	return 0;
	
}



