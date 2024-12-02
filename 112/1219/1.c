#include <stdio.h>
#include <time.h>


void aPrint(int *a, int size){
	
	int i;
	for(i=0; i<size; i++) printf("%12d ", a[i]);
		printf("\n");
}


void swap(int *a, int i, int j){
	int temp=0;
	temp=a[i]; a[i]=a[j]; a[j]=temp;
}


void initArray(int *b, int n){
	// Seed the random number generator with the current time
	srand(time(NULL));
	int  i, j;
	for(i=0; i<n; i++) b[i]=rand();	
	
	aPrint(b, n);		
	
	
}

void bubbleSort(int *a, int n){
			
	int i, j;
	for(i=0; i<n; i++) 
	for(j=i+1; j<n; j++) 
		if(a[i] > a[j]) swap(a, i,j);
	aPrint(a, n);	
}



int main ()
{
	
	int n=10;
	int a[n];
    initArray(a, n);
	bubbleSort(a, n);
    
	return 0;
}



