#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10; // Initialize with some values
    }
    printf("Address of array inside createArray: %p\n", arr); // Print address inside sub-function
    return arr;
}

int main() {
    int* myArray = createArray(5);
    if (myArray != NULL) {
        printf("Address of array in main: %p\n", myArray); // Print address in main
        for (int i = 0; i < 5; i++) {
            printf("%d ", myArray[i]);
        }
        printf("\n");
        free(myArray); // Free the memory
    }
    return 0;
}