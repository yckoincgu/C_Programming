#include <stdio.h>
#include <stdlib.h>
	
void dPrint(int *digits, int size){
	int i;
	for(i=0; i<size; i++) printf("%d", digits[i]);
		printf("\n");
}

int quotientBy10(int *digits, int i, int n){
	digits[i]= n % 10; n=n/10;
	return n;
}

void carryOver(int *digits, int i){
	digits[i-1]=digits[i-1]+1;
}

int add(int *adigits, int *bdigits, int *rdigits, int size)
{
	int i=0;
	for(i=size-1; i>-1; i--){
		if(adigits[i]+bdigits[i]>9){
			rdigits[i]=adigits[i]+bdigits[i]+rdigits[i]-10;
			carryOver(rdigits,i);}
		else rdigits[i]=adigits[i]+bdigits[i]+rdigits[i];	
	}
}

int main(void)
{
	int a=124, b=958, i, r;
	int adigits[32], bdigits[32], rdigits[32], size=sizeof(adigits)/sizeof(*adigits);
	
	for(i=size-1; i>=0; i--) a=quotientBy10(adigits, i, a);
	dPrint(adigits, size);
	printf("\n");
	for(i=size-1; i>=0; i--) b=quotientBy10(bdigits, i, b);
	dPrint(bdigits, size);
	for(i=size-1; i>=0; i--) r=quotientBy10(rdigits, i, 0);
	dPrint(rdigits, size);	
	
	add(adigits, bdigits, rdigits, size);
	dPrint(rdigits, size);
	
	return 0;
}


