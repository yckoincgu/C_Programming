#include <stdio.h>

int x[5]={3,2,5,1,4};

void partition(int *p, int low, int high);
void printx(x);


void partition(int *p, int low, int high){

}


void printx(int *p){
    int i=0, size=(sizeof(x)/sizeof(x[0]));

    for(i=0; i<size; i++ )
        printf("%d ", x[i]);
    printf("\n");    
}

int main()
{
    printx(x);
    partition(xa, 2,3);



    return 0;
}