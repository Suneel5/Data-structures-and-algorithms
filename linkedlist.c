#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Attach the new node to the last node
    current->next = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node** head, int data) {
    // If the list is empty, return
    if (*head == NULL) {
        return;
    }
    
    // If the node to be deleted is the head, update the head
    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    // Traverse to find the node to be deleted
    struct Node* current = *head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;
    
    // Insert nodes
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    
    // Print the linked list
    printf("Linked List: ");
    printList(head);
    
    // Delete a node
    deleteNode(&head, 2);
    
    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printList(head);
    
    return 0;
}
