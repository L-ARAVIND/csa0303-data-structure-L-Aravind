#include <stdio.h>
int queue[5];
int front = 0, rear = -1;
void enqueue(int value) {
    if (rear == 4) {printf("Queue is full\n");} else {rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);}}
void dequeue() {
    if (front > rear) {printf("Queue is empty\n");} else {
        printf("Dequeued %d\n", queue[front]);front++;}
}
void display() {
    if (front > rear) {
        printf("Queue is empty\n");} else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);}printf("\n");}}
int main() {
    int choice, value;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }return 0;
}

