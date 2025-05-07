#include <stdio.h>
int stack[5];
int top = -1;
void push(int value) {
    if(top == 4) {
        printf("Stack is full\n");} else {top++;stack[top] = value;printf("Pushed %d\n", value);}
}
void pop() {
    if(top == -1) {
        printf("Stack is empty\n");} else {printf("Popped %d\n", stack[top]);top--;}
}
void peek() {
    if(top == -1) {
        printf("Stack is empty\n");} else {printf("Top is %d\n", stack[top]);}
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {printf("Enter value: ");scanf("%d", &value);push(value);
        } else if(choice == 2) {pop();
        } else if(choice == 3) {peek();
        } else if(choice == 4) {break;
        } else {printf("Invalid choice\n");}
    }return 0;
}

