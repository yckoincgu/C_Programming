#include <stdio.h>

int x[5]={3,2,5,1,4};
int size=(sizeof(x)/sizeof(x[0]));

void swap(int *a, int i, int j);
void partition(int *a, int low, int high);
void printx(int *a);

void partition(int *a, int low, int high){
    int i=low, p=low;
    for(p=low, i=low; i<high; i++){
        
        if(a[i]<a[high]){
            if (i>p) swap(a,i,p);
            p++;            
        } 

    }
    swap(a,p,high);

}

void swap(int *a, int i, int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}


void printx(int *a){
    int i=0;

    for(i=0; i<size; i++ )
        printf("%d ", a[i]);
    printf("\n");    
}

int main()
{

    printx(x);
    partition(x,0,4);
    printf("After partition, the array is sorted as ");
    printx(x);



    return 0;
}