#include <stdio.h>

void qsort(int *p, int low, int high) {
    if (low < high) {
        int pivot = p[low], left = low + 1, right = high;
        while (left <= right) {
            while (left <= high && p[left] <= pivot) left++;
            while (right >= low && p[right] > pivot) right--;
            if (left < right) {
                int temp = p[left]; p[left] = p[right]; p[right] = temp;
            }
        }
        p[low] = p[right]; p[right] = pivot;
        qsort(p, low, right - 1);
        qsort(p, right + 1, high);
    }
}

int main() {
	int k;
    int xy[5] = {1, 3, 5, 2, 4};
    qsort(xy, 0, 4);
    for ( k = 0; k < 5; k++) printf("%d ", xy[k]);
    printf("\n");
    return 0;
}