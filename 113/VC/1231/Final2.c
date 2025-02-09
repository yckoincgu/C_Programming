#include <stdio.h>

int main(){
#include <time.h>
    srand(time(NULL));
    int arr[10];
    int n =10;
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        }
    for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    return 0;
}