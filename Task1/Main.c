#include <stdio.h>
#include <stdlib.h>

// Define a struct for a singly linked list node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Delete the given node from the list
void deleteNode(Node** head, Node* nodeToDelete) {
    // If the head node is the one to delete
    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
        free(nodeToDelete);
        return;
    }
    // Otherwise, find the previous node and unlink the node to delete
    Node* current = *head;
    while (current->next && current->next != nodeToDelete) {
        current = current->next;
    }
    if (current->next) {
        current->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

// Delete all odd nodes from the list
void deleteOddNodes(Node** head) {
    Node* current = *head;
    while (current) {
        Node* nextNode = current->next;
        if (current->data % 2 == 1) {
            deleteNode(head, current);
        }
        current = nextNode;
    }
}

// Print the list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a test list
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Delete odd nodes
    deleteOddNodes(&head);

    // Print the updated list
    printf("List with odd nodes removed: ");
    printList(head);

    return 0;
}
