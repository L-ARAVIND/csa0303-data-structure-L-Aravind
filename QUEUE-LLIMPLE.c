#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Empty!!\n");
    } else {
        struct node *temp = front;
        front = front->next;
        printf("Deleted Element: %d\n", temp->data);
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
    }
}

