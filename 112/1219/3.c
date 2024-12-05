#include <stdio.h>
 
int xarry[5]={1,2,3,4,5};
void swap(int *P ,int i , int j );

void swap(int *P ,int i , int j ){
    int tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
}
   
 
int main (){
    swap(xarry,1,3);
    int i=0;
    int *p=xarry;   // array name can be treated as variable name or address
    p=xarry;
    p=&xarry[0];

    for(i=0; i< 5; i++)
        printf("%d ", p[i]);
    
    return 0;
}