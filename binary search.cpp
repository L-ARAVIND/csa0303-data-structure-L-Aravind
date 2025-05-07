#include <stdio.h>

int main() {
    int arr[5] = {5, 10, 15, 20, 25}; 
    int key, low = 0, high = 4, mid;

    printf("Enter number to search: ");
    scanf("%d", &key);

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("%d found at position %d\n", key, mid + 1);
            return 0;
        }
        else if(key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d not found in the array\n", key);
    return 0;
}

