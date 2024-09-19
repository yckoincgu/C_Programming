#include <stdio.h>
int main()
{
   int a,b;
   for(int a=0;a<=4;a++)
	{
		printf("\n");
		
		for(int b=4;b>=a;b--)
		{
			printf("*"); 
		}	
	}
	

	return 0;
}
