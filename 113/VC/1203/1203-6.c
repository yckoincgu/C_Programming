#include <stdio.h>

int xy[5]={3, 2, 5, 1, 4};

void swap(int *P ,int i , int j );
int  partition(int *p, int low, int high);
void printxy(int *p, int sizeofArray);
void quicksort(int *p, int low, int high);

void quicksort(int *p, int low, int high){
    int pivot= partition(xy, low, high);

    if(low < pivot-1) quicksort(xy, low, pivot-1);
    if(pivot+1 < high) quicksort(xy, pivot+1, high);        

}

void printxy(int *p, int sizeofArray){
    int i=0;
    for(i=0; i< sizeofArray; i++) printf("%d ",p[i]);
    printf("\n");
}
int partition(int *p, int low, int high){

    int i=0,pivot=0;  // assume high as pivot candidate, then find its indexing position
    for(i=low,pivot=low; i<high+1; i++){
        if(p[i]<p[high]) {
            if(i>pivot) swap(xy, i, pivot);
            pivot++;
        }  
    }
    swap(xy, pivot, high);
    
    //printf("pivot = %d \n", pivot);
    //printf("sizeofArry = %d\n", (int)sizeof(xarray)/sizeof(xarray[0]));
    return pivot;
}

void swap(int *P ,int i , int j ){
    int tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
}
int main (){
    printxy(xy, (int)sizeof(xy)/sizeof(xy[0])); 
    quicksort(xy, 0, (int)sizeof(xy)/sizeof(xy[0])-1);
    printxy(xy, (int)sizeof(xy)/sizeof(xy[0])); 

    return 0;
}