#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;}
    if (front == -1){
        front = 0;}
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Empty!!\n");
        return;
    }
    printf("Deleted Element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
