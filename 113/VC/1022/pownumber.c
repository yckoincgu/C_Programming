#include <stdio.h>
#include <math.h>

double n,x;
int i;
double sum = 0;
int length_count = 0;
int main(){
scanf("%lf",&n);
x=n ;
while (n>=1){
    length_count += 1;
    n=n/10;
}
for (i=0;i<length_count;i++){
    n=n*10;
    sum += pow((int)trunc(n),length_count);
    n=n-(int)trunc(n);
}
if (x == sum){
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}