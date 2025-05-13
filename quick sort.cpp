#include <stdio.h>

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high], i = low - 1, temp;
        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                temp = a[++i]; a[i] = a[j]; a[j] = temp;
            }
        }
        temp = a[i+1]; a[i+1] = a[high]; a[high] = temp;
        int pi = i + 1;
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int a[] = {7, 2, 1, 6, 8}, n = 5;
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

