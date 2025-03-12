#include <stdio.h>

int* createArray(int size) {
    int arr[size]; // Array declared on the stack
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    printf("Address of array inside createArray: %p\n", arr);
    return arr; // Returning a pointer to a local array!
}

int main() {
    int* myArray = createArray(5);
    /*  the memory that myArray points to is no longer valid. 
        It has been deallocated when createArray returned.
    */
    if (myArray != NULL) {
        printf("Address of array in main: %p\n", myArray);
        for (int i = 0; i < 5; i++) {
            printf("%d ", myArray[i]);
        }
        printf("\n");
        // No need to free (but it's invalid memory anyway)
    }
    return 0;
}