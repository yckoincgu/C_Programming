#include <stdio.h>
int main ()
  
{
	int i, j, a;
	for(i=1;i<5;i++)
   {
	 for(j=4;j>0;j--)
       
	      if(i>=j)printf("*");
        	else printf("0");  
	      printf("\n");
    }
    
     
return 0;
}
