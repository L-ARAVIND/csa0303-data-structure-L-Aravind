#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key, i;

    printf("Enter number to search: ");
    scanf("%d", &key);

    for(i = 0; i < 5; i++) {
        if(arr[i] == key) {
            printf("%d found at position %d\n", key, i + 1);
            return 0;
        }
    }

    printf("%d not found in the array\n", key);
    return 0;
}

