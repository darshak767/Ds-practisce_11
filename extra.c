#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end of Circular Linked List
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->next = newNode;  // First node points to itself
        *head = newNode;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node from the front of Circular Linked List
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* last = *head;

    if ((*head)->next == *head) {  // Only one node in the list
        free(*head);
        *head = NULL;
    } else {
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to display Circular Linked List
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular Linked List: ");
    
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(Back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Front\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                deleteFront(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
