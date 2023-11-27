// C language, binary code for decimal value

#include <stdio.h>

void printBinary(int n){
	
	int bits[32];
	int  i;
	
	if (n==0) printf("the binary value is 0");
	i=n%2;
	
	for(i=31; i>=0; i--){
		bits[i]= n % 2;
		n=n/2;
	}
	
	for(i=0; i<32; i++)
		printf("%d", bits[i]);
		
}


int main ()
  
{
	 int a;
	
	while(a<20)
   {
		(a>5)?a++:a--; 
	    if(a>0) printf("%d\n", a);
    }
    
    printBinary(10);
    
    
return 0;
}
