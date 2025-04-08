#include <stdio.h>


void bPrint(int *bits, int size){
	int flag=0;	// 
	int i;
		for(i=0; i<size; i++) {
			if(bits[i] != 0) flag=1;
			if(flag!=0) printf("%d", bits[i]);
			else printf("%c", ' ');
		}	
		printf("\n");
}


void printBinary(int n){
	int bits[32];
	
	int  i, m;
	int  sFlag;
	if (n==0) sFlag =0;
	if (n>0) sFlag  =1;
	if (n<0) sFlag  =2;
	
	switch(sFlag){
		case 0:
			printf("the binary value is 0");
			break;
		case 1:
			for(i=31; i>=0; i--){bits[i]= n % 2; n=n/2;}
			bPrint(bits, 32);
			break;
		case 2:
			m=-n;
			for(i=31; i>=0; i--){
				bits[i]= m % 2;
				m=m/2;}
			bPrint(bits, 32);
			for(i=0; i<32; i++)
				bits[i]= (bits[i]==1)?0:1; 
			
			bPrint(bits, 32);
			for(i=31; i>=0; i--){
				if(i==31) 	
					if((bits[i]+1)>1) {
						bits[i-1]=bits[i-1]+1;
						bits[i]=0; }
					else bits[i]=1;
				else
				    if(bits[i]>1)  {
						bits[i-1]=bits[i-1]+1; 
						bits[i]=0;} 
			}
			bPrint(bits, 32);	
			break;
		default:
			printf("Execution error happened");			
						
			
	}

}



