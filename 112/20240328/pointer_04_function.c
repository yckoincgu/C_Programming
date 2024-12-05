#include <stdio.h>

// Function prototype
void printxy(int *arr, int size);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the function, passing a pointer, arr, to the array
    printxy(arr, size);

    return 0;
}

// Function definition
void printxy(int *arr, int size) {
	/* In C, there isn't a specific delimiter for integer arrays 
	   like the null character '\0' for strings. 
	*/   
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

