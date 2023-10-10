#include <stdio.h>
int main()
{
   
   for(int a=0;a<=4;a++)
	{
	printf("\n");
	
	for(int b=0;b<=4;b++)
	{
	if(a==b)
	printf("(%d,%d)",a,b); 
	else
	printf("     ");
	}	
	}
	

return 0;
}
