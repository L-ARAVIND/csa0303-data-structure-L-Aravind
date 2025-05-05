#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *head = NULL;

void createList();
void displayList();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition();
void searchElement();
void updateElement();

int main() {
    int choice;
    
    while(1) {
        printf("\n\n1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at position\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Delete from position\n");
        printf("9. Search element\n");
        printf("10. Update element\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: createList(); break;
            case 2: displayList(); break;
            case 3: insertAtBeginning(); break;
            case 4: insertAtEnd(); break;
            case 5: insertAtPosition(); break;
            case 6: deleteFromBeginning(); break;
            case 7: deleteFromEnd(); break;
            case 8: deleteFromPosition(); break;
            case 9: searchElement(); break;
            case 10: updateElement(); break;
            case 11: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

void createList() {
    struct node *temp, *newNode;
    int n, data, i;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid number of nodes\n");
        return;
    }
    
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    
    head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;
    temp = head;
    
    for(i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->link = NULL;
        temp->link = newNode;
        temp = temp->link;
    }
    
    printf("List created successfully\n");
}

void displayList() {
    struct node *temp;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void insertAtBeginning() {
    struct node *newNode;
    int data;
    
    printf("Enter data to insert: ");
    scanf("%d", &data);
    
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
    
    printf("Node inserted at beginning\n");
}

void insertAtEnd() {
    struct node *newNode, *temp;
    int data;
    
    printf("Enter data to insert: ");
    scanf("%d", &data);
    
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    
    if(head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    
    printf("Node inserted at end\n");
}

void insertAtPosition() {
    struct node *newNode, *temp;
    int data, pos, i;
    
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &data);
    
    if(pos == 1) {
        insertAtBeginning();
        return;
    }
    
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    temp = head;
    for(i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->link;
    }
    
    if(temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    
    newNode->link = temp->link;
    temp->link = newNode;
    
    printf("Node inserted at position %d\n", pos);
}

void deleteFromBeginning() {
    struct node *temp;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    head = head->link;
    free(temp);
    
    printf("Node deleted from beginning\n");
}

void deleteFromEnd() {
    struct node *temp, *prev;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if(head->link == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
        return;
    }
    
    temp = head;
    while(temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    
    prev->link = NULL;
    free(temp);
    
    printf("Node deleted from end\n");
}

void deleteFromPosition() {
    struct node *temp, *prev;
    int pos, i;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Enter position: ");
    scanf("%d", &pos);
    
    if(pos == 1) {
        deleteFromBeginning();
        return;
    }
    
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }
    
    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    prev->link = temp->link;
    free(temp);
    
    printf("Node deleted from position %d\n", pos);
}

void searchElement() {
    struct node *temp;
    int data, pos = 1, found = 0;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Enter element to search: ");
    scanf("%d", &data);
    
    temp = head;
    while(temp != NULL) {
        if(temp->data == data) {
            printf("Element %d found at position %d\n", data, pos);
            found = 1;
        }
        temp = temp->link;
        pos++;
    }
    
    if(!found) {
        printf("Element %d not found in the list\n", data);
    }
}

void updateElement() {
    struct node *temp;
    int oldData, newData, found = 0;
    
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Enter element to update: ");
    scanf("%d", &oldData);
    printf("Enter new value: ");
    scanf("%d", &newData);
    
    temp = head;
    while(temp != NULL) {
        if(temp->data == oldData) {
            temp->data = newData;
            found = 1;
        }
        temp = temp->link;
    }
    
    if(found) {
        printf("Element updated successfully\n");
    } else {
        printf("Element not found in the list\n");
    }
}