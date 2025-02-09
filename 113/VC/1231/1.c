#include <stdio.h>
#include <stdlib.h>

int x[10];

int main(){
    for(int i = 0; i < 10; i++) {
        x[i] = rand() % 100;
 }
    for(int i = 0; i < 10; i++) {
        printf("%d ", x[i]);
    }
    
    return 0;

}
