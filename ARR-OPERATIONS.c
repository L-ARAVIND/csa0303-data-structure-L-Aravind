#include <stdio.h>

int main() {
    int arr[]={7,21,18,45,93,3,11,1,99,17};
    int size =sizeof(arr)/sizeof(arr[0]);
    int choice, element, position, i;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Find\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);

                if (position >= 0 && position <= size) {
                    for (i = size; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = element;
                    size++;
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Invalid position.\n");
                }
                break;

            case 2: // Update
                printf("Enter position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (position >= 0 && position < size) {
                  printf("Enter new element: ");
                  scanf("%d", &element);
                  arr[position] = element;
                  printf("Element updated successfully.\n");
                } else {
                  printf("Invalid position.\n");
                }
                break;

            case 3: // Delete
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);

                if (position >= 0 && position < size) {
                    for (i = position; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("Element deleted successfully.\n");
                } else {
                    printf("Invalid position.\n");
                }
                break;

            case 4: // Find
                printf("Enter element to find: ");
                scanf("%d", &element);
                int found = 0;
                for (i = 0; i < size; i++) {
                    if (arr[i] == element) {
                        printf("Element found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Element not found in the array.\n");
                }
                break;

            case 5: // Display
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 6: // Exit
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


