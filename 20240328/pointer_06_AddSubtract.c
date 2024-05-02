#include <stdio.h>
#include <stdlib.h>
	
void dPrint(int *digits, int size){
	int i;
	char initZero=0;
	for(i=0; i<size; i++) {
		if(digits[i] == initZero && initZero == 0) {printf(" "); continue;}
		else{
			initZero=1;
			if(digits[i] != -1)
				printf("%d", digits[i]);
			else printf("-");	
		}
	}	
		printf("\n");

}



int quotientBy10(int *digits, int i, int n){
	digits[i]= n % 10; n=n/10;
	return n;
}

void carryOver(int *digits, int i){
	digits[i-1]=digits[i-1]+1;
}
void borrow(int *digits, int i){
	digits[i-1]=digits[i-1]-1;
}


void add(int *adigits, int *bdigits, int *rdigits, int size)
{
	int i=0;
	for(i=size-1; i>-1; i--){
		if(adigits[i]+bdigits[i]>9){
			rdigits[i]=adigits[i]+bdigits[i]+rdigits[i]-10;
			carryOver(rdigits,i);}
		else rdigits[i]=adigits[i]+bdigits[i]+rdigits[i];	
	}
}

void negativeSubtract(int *adigits, int *bdigits, int *rdigits, int size){
	int i=0;
	for(i=size-1; i>-1; i--){
		if((adigits[i] == 0) && (bdigits[i] == 0))
		{
		 	rdigits[i]=-1;
		 	break;
		}
		if(bdigits[i]-adigits[i]<0){
			rdigits[i]=bdigits[i]-adigits[i]+rdigits[i]+10;
			borrow(rdigits,i);}
		else rdigits[i]=bdigits[i]-adigits[i]+rdigits[i];	
	}
	dPrint(rdigits, size);
}

void positiveSubtract(int *adigits, int *bdigits, int *rdigits, int size){
	int i=0;
	for(i=size-1; i>-1; i--){
		if(adigits[i]-bdigits[i]<0){
			rdigits[i]=adigits[i]-bdigits[i]+rdigits[i]+10;
			borrow(rdigits,i);}
		else rdigits[i]=adigits[i]-bdigits[i]+rdigits[i];	
	}
	dPrint(rdigits, size);
}


int main(void)
{
	int a=125, b=984, i, r;
	int adigits[32], bdigits[32], rdigits[32], size=sizeof(adigits)/sizeof(*adigits);
	printf("addition \n");
	for(i=size-1; i>=0; i--) a=quotientBy10(adigits, i, a);
	dPrint(adigits, size);
	
	for(i=size-1; i>=0; i--) b=quotientBy10(bdigits, i, b);
	dPrint(bdigits, size);
	for(i=size-1; i>=0; i--) r=quotientBy10(rdigits, i, 0);
	//dPrint(rdigits, size);	
	add(adigits, bdigits, rdigits, size);
	dPrint(rdigits, size);
	printf("\n");
	printf("substraction \n");
	dPrint(adigits, size);
	dPrint(bdigits, size);
	for(i=size-1; i>=0; i--) rdigits[i]=0;	
	//dPrint(rdigits, size);
	
	if(a>b) positiveSubtract(adigits, bdigits, rdigits, size);
	else 	negativeSubtract(adigits, bdigits, rdigits, size);
	
	
	return 0;
}


