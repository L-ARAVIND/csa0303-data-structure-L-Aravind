#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *head = NULL, *t, *temp;

int main() {
    int i, value, choice, pos, search_val, new_val;
    
    // Create initial circular list with 5 nodes
    for (i = 0; i < 5; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);
        temp->data = value;
        
        if (head == NULL) {
            head = temp;
            temp->link = head;  // Points to itself (circular)
            t = temp;
        } else {
            t->link = temp;
            temp->link = head;  // New node points back to head
            t = temp;
        }
    }
    
    while(1) {
        printf("\nCircular Linked List: ");
        if (head != NULL) {
            temp = head;
            do {
                printf("%d --> ", temp->data);
                temp = temp->link;
            } while (temp != head);
        }
        printf("HEAD\n");
        
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Search element\n");
        printf("8. Update element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Insert at beginning
                printf("Enter value to insert: ");
                scanf("%d", &value);
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = value;
                
                if (head == NULL) {
                    head = temp;
                    temp->link = head;
                } else {
                    t = head;
                    while(t->link != head) {
                        t = t->link;
                    }
                    temp->link = head;
                    head = temp;
                    t->link = head;  // Update last node's link
                }
                break;
                
            case 2: // Insert at end
                printf("Enter value to insert: ");
                scanf("%d", &value);
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = value;
                temp->link = head;  // New node points to head
                
                if (head == NULL) {
                    head = temp;
                    temp->link = head;
                } else {
                    t = head;
                    while(t->link != head) {
                        t = t->link;
                    }
                    t->link = temp;
                }
                break;
                
            case 3: // Insert at position
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = value;
                
                if (pos == 1) {
                    if (head == NULL) {
                        head = temp;
                        temp->link = head;
                    } else {
                        t = head;
                        while(t->link != head) {
                            t = t->link;
                        }
                        temp->link = head;
                        head = temp;
                        t->link = head;
                    }
                } else {
                    t = head;
                    for(i = 1; i < pos-1 && t->link != head; i++) {
                        t = t->link;
                    }
                    if (t->link == head && i < pos-1) {
                        printf("Invalid position!\n");
                        free(temp);
                    } else {
                        temp->link = t->link;
                        t->link = temp;
                    }
                }
                break;
                
            case 4: // Delete from beginning
                if (head == NULL) {
                    printf("List is empty!\n");
                } else if (head->link == head) {
                    free(head);
                    head = NULL;
                } else {
                    t = head;
                    while(t->link != head) {
                        t = t->link;
                    }
                    temp = head;
                    head = head->link;
                    t->link = head;
                    free(temp);
                }
                break;
                
            case 5: // Delete from end
                if (head == NULL) {
                    printf("List is empty!\n");
                } else if (head->link == head) {
                    free(head);
                    head = NULL;
                } else {
                    t = head;
                    while(t->link->link != head) {
                        t = t->link;
                    }
                    free(t->link);
                    t->link = head;
                }
                break;
                
            case 6: // Delete from position
                printf("Enter position: ");
                scanf("%d", &pos);
                
                if (head == NULL) {
                    printf("List is empty!\n");
                } else if (pos == 1) {
                    if (head->link == head) {
                        free(head);
                        head = NULL;
                    } else {
                        t = head;
                        while(t->link != head) {
                            t = t->link;
                        }
                        temp = head;
                        head = head->link;
                        t->link = head;
                        free(temp);
                    }
                } else {
                    t = head;
                    for(i = 1; i < pos-1 && t->link != head; i++) {
                        t = t->link;
                    }
                    if (t->link == head) {
                        printf("Invalid position!\n");
                    } else {
                        temp = t->link;
                        t->link = temp->link;
                        free(temp);
                    }
                }
                break;
                
            case 7: // Search element
                printf("Enter value to search: ");
                scanf("%d", &search_val);
                
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    t = head;
                    i = 1;
                    do {
                        if(t->data == search_val) {
                            printf("Value %d found at position %d\n", search_val, i);
                            break;
                        }
                        t = t->link;
                        i++;
                    } while (t != head);
                    if (t == head && t->data != search_val) {
                        printf("Value %d not found in list\n", search_val);
                    }
                }
                break;
                
            case 8: // Update element
                printf("Enter value to update: ");
                scanf("%d", &search_val);
                printf("Enter new value: ");
                scanf("%d", &new_val);
                
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    t = head;
                    do {
                        if(t->data == search_val) {
                            t->data = new_val;
                            printf("Value updated successfully\n");
                            break;
                        }
                        t = t->link;
                    } while (t != head);
                    if (t == head && t->data != search_val) {
                        printf("Value %d not found in list\n", search_val);
                    }
                }
                break;
                
            case 9: // Exit
                // Free memory before exiting
                if (head != NULL) {
                    t = head;
                    do {
                        temp = t;
                        t = t->link;
                        free(temp);
                    } while (t != head);
                    head = NULL;
                }
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}