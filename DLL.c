#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
} *head = NULL, *t, *temp;

int main() {
    int i, value;
    
    for (i = 0; i < 5; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);
        temp->data = value;
        temp->link = NULL;
        
        if (head == NULL) {
            head = temp;
            t = temp;
        } else {
            t->link = temp;
            t = temp;
        }
    }
    
    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
    
    return 0;
}