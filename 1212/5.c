#include <stdio.h>
int bits[32];

void bPrint(int *bits, int size){
	
	int i;
		for(i=0; i<size; i++) printf("%d", bits[i]);
		printf("\n");
}

int whichCase(int n){
	int sFlag=-1;
	
	if (n==0) 	sFlag =0;
	if (n>0) 	sFlag  =1;
	if (n<0) 	sFlag  =2;
	return sFlag;	
}

int quotientBy2(int i, int n){
	bits[i]= n % 2; n=n/2;
	return n;
}

void carryOver(int i){
	bits[i-1]=bits[i-1]+1;
	bits[i]=0; 
}


void printBinary(int n){
	
	
	int  i, m;
	int  sFlag=whichCase(n);

	
	switch(sFlag){
		case 0:
			printf("the binary value is 0");
			break;
		case 1:
			for(i=31; i>=0; i--) n=quotientBy2(i,n);
			bPrint(bits, 32);
			break;
		case 2:
			m=-n;
			for(i=31; i>=0; i--) m=quotientBy2(i,m);
			bPrint(bits, 32);
			
			for(i=0; i<32; i++)  bits[i]= (bits[i]==1)?0:1; 
			bPrint(bits, 32);
			
			for(i=31; i>=0; i--){
				if(i==31) 	
					if((bits[i]+1)>1) carryOver(i);
					else bits[i]=1;
				else
				    if(bits[i]>1) carryOver(i);
			}
			bPrint(bits, 32);	
			break;
		default:
			printf("Execution error happened");			
						
			
	}

}



int main ()
  
{
    printBinary(-10);
	return 0;
}

