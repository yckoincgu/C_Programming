#include <stdio.h>

int xy[5]={1,4,3,2,5};

void swap(int *P ,int i , int j );
void swap(int *P ,int i , int j ){
    int tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
}
int main (){

    int i;
    int j;
    for(i=0; i< 5; i++)
     for(j=i+1; j< 5; j++)
      if(xy[i]>xy[j])
        swap(xy, i, j);
    

     for(i=0; i< 5; i++) printf("%d ",xy[i]);

    return 0;
}