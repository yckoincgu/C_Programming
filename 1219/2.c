#include <stdio.h>
#include <time.h>


void aPrint(int *a){
	int i, size=sizeof(a);;
	for(i=0; i<size; i++) printf("%d ", a[i]);
		printf("\n");
}


void swap(int *a, int i, int j){
	int temp=0;
	temp=a[i]; a[i]=a[j]; a[j]=temp;
}


void initArray(int *b){
	// Seed the random number generator with the current time
	srand(time(NULL));
	int  i, j, n=sizeof(b);

	for(i=0; i<n; i++) b[i]=rand();	
	
	aPrint(b);		
	
	
}

void bubbleSort(int *a){
	int i, j, n=sizeof(a);;
	for(i=0; i<n; i++) 
	for(j=i+1; j<n; j++) 
		if(a[i] > a[j]) swap(a, i,j);
	aPrint(a);	
}



int main ()
{
	int n=10;
	int a[n];
    initArray(a);
	bubbleSort(a);
    
	return 0;
}




