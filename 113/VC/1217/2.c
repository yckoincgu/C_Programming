#include <stdio.h>

int x[5]={3,2,5,1,4};
int size=(sizeof(x)/sizeof(x[0]));

void swap(int *a, int i, int j);
int partition(int *a, int low, int high);
void printx(int *a);

int partition(int *a, int low, int high){
    int i=low, p=low;
    for(p=low, i=low; i<high; i++){
        if(a[i]<a[high]) 
            if (i>p) {swap(a,i,p); p++;}
            else p++;
        
    }
    swap(a,p,high);
    return p;

}

void swap(int *a, int i, int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}

void qSort(int *a, int low, int high){
    if(!(low<high)) return;
    int p=partition(a,low,high);
    qSort(a, low, p-1);
    qSort(a, p+1, high);

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
    qSort(x,0,4);
    printf("After partition, the array is sorted as ");
    printx(x);



    return 0;
}