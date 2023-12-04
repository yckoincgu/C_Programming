#include <stdio.h>

void printBinary(int n){
	
	int bits[32];
	int  i, m;
	
	
	if (n==0) printf("the binary value is 0");
	else if(n>0){
			for(i=31; i>=0; i--){
				bits[i]= n % 2;
				n=n/2;}}
		else{
			m=-n;
			for(i=31; i>=0; i--){
				bits[i]= m % 2;
				m=m/2;}
			bPrint(bits, 32);
			for(i=0; i<32; i++){
				if(bits[i]==1) bits[i]=0;
				else  bits[i]=1;
			}
			bPrint(bits, 32);
			for(i=31; i>=0; i--){
				if(i==31) 	if((bits[i]+1)>1) {
								bits[i-1]=bits[i-1]+1;
								bits[i]=0; }
						   	else bits[i]=1;
				else       	if(bits[i]>1)  {
								bits[i-1]=bits[i-1]+1; bits[i]=0;} 
			}
			bPrint(bits, 32);			
				
		}	
}

void bPrint(int *bits, int size){
	int i;
		for(i=0; i<size; i++) printf("%d", bits[i]);
		printf("\n");
}


int main ()
  
{
    printBinary(-10);
	return 0;
}
