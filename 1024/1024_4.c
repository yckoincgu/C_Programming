#include <stdio.h>
int main ()
  
{
	int i, j, a;
	for(i=1;i<4;i++)
   {
	 for(j=4;j>0;j--)
       
	      if(i>=j)printf("*");
        	else printf(" ");  
	      printf("\n");
    }
     for(a=0;a<4;a++)
     printf("*");
return 0;
}
