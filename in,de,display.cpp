#include <stdio.h>
int main() {
    int arr[10], size = 0, i, element, position, choice;
    while(1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            if (size < 10) {
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (1 to %d): ", size + 1);
                scanf("%d", &position);
                for (i = size; i >= position; i--) {
                    arr[i] = arr[i - 1];}
                arr[position - 1] = element;
                size++;}else {
                printf("Array is full!\n");}
				} 
        else if (choice == 2) {
            if (size > 0) {
                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &position);
                for (i = position - 1; i < size - 1; i++) {
                    arr[i] = arr[i + 1];}
                size--;} else {
                printf("Array is empty!\n");}
        }
        else if (choice == 3) {
            if (size > 0) {
                printf("Array elements: ");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            } else {
                printf("Array is empty!\n");
            }
        }
        else if (choice == 4) {
            break;
        }else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

