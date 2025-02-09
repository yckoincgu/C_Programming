#include <stdio.h>

int partition(int x[], int low, int high) {
    int pivot = x[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (x[j] <= pivot) {
            i++;
            int temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }

    int temp = x[i + 1];
    x[i + 1] = x[high];
    x[high] = temp;

    return i + 1;
}

void quickSort(int x[], int low, int high) {
    if (low < high) {
        int pi = partition(x, low, high);
        quickSort(x, low, pi - 1);
        quickSort(x, pi + 1, high);
    }
}

int main() {
    int x[10] = {64, 25, 12, 22, 11, 90, 75, 33, 5, 56};
    
    int n = 10;
    quickSort(x, 0, n - 1);
    
    printf("Sorted array in increasing order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}
