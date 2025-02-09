#include <stdio.h>

void partition(int a[], int B) {

    for (int i = 0; i < B - 1; i++) {
        for (int j = 0; j < B - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    
    int a[10] = {64, 25, 12, 2, 11, 58, 77, 33, 5, 46};
    int B = 10;
    partition(a, B);
    
    printf("Sorted array in increasing order:\n");
    for (int i = 0; i < B; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
