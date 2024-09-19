#include <stdio.h>
int main ()
  
{
	int i, j, a;
	
	for(i=0;i<4;i++)
   {
	 for(j=0;j<4;j++)
	 
	 if(i<=j)printf("*");
    	else printf(" ");
	      
	      printf("\n");
    }
return 0;
}
