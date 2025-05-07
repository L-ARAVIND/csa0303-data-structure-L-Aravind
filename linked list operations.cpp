#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// PUSH operation
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full (Overflow)\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

// POP operation
void pop() {
    if (top == -1) {
        printf("Stack is empty (Underflow)\n");
    } else {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}

// PEEK operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

