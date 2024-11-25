// C language, binary code for decimal value

#include <stdio.h>

void printBinary(int n){
	
	int bits[32];
	int  i;
	
	if (n==0) printf("the binary value is 0");
	
	
	for(i=31; i>=0; i--){
		bits[i]= n % 2;
		n=n/2;
	}
	
	for(i=0; i<32; i++)
		printf("%d", bits[i]);
	printf("\n");	
		
}


int main ()
  
{
	 int a=15;
	printf("run while loop to increase integer %d to 20\n", a);
	while(a<20)
   {
		(a>5)?a++:a--; 
	    if(a>0) printf("%d\n", a);
    }

    printf("\nTransfter integer %d to binary digits. \n", a);
    printBinary(a);

    
    
return 0;
}
