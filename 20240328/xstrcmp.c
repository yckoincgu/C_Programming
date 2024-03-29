#include <stdio.h>

int (xstrcmp)(const char *s1, const char *s2)
{
	unsigned char uc1, uc2;
	/* Move s1 and s2 to the first differing characters
	in each string, or the ends of the strings if they
	are identical. */
	while (*s1 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
	/* 
		Compare the characters as unsigned char and return the difference. 
	*/
	uc1 = (*(unsigned char *) s1);
	uc2 = (*(unsigned char *) s2);
	return ((uc1 < uc2) ? -1 : (uc1 > uc2));
}

int main(void)
{
	char s1[]="test";
	char s2[]="test";
	char *ptr;
	ptr=s1;
	if(xstrcmp(s1, s2)==0) {
		printf("They are the same string: ");
		while (*ptr != '\0') printf("%c", *ptr++);}
	else printf("They are not the same string");	
}



