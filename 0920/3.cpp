#include <stdio.h>
int main()
{
   int a, b;
   for(a=0;a<=4;a++)
	{
		printf("\n");
		
		for(b=0;b<=4;b++)
		{
			if(a==b) printf("(%d,%d)",a,b); 
			else printf("     ");
		}	
	}

	return 0;
}