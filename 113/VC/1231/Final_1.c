#include <stdio.h>
#include <stdlib.h>

int main() {
#include <time.h>
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        }
    return 0;   
}
