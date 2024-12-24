#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
      int j;
    for ( j = low; j < high; j++) {
        
        if (arr[j] <= pivot) {
            i++; 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; 
}

void printArray(int arr[], int size) {
         int i;
    for ( i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 2, 1, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int pivotIndex = partition(arr, 0, n - 1); 

    printf("Partitioned array: \n");
    printArray(arr, n); 
  

    return 0; 
}