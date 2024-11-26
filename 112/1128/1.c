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
	 int a;

	printf("\n input an integer to make binary digits  \n", a);
	scanf("%d",&a);
    printBinary(a);
	printf("\n");	

    
return 0;
}
