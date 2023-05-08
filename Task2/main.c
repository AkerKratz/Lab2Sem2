#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void deleteOdd(Node** head_ref) {
    Node* current = *head_ref;
    Node* temp = NULL;
    while (current != NULL) {
        if (current->data % 2 != 0) {
            if (current == *head_ref) {
                *head_ref = current->next;
                (*head_ref)->prev = NULL;
                free(current);
                current = *head_ref;
            }
            else if (current->next == NULL) {
                current->prev->next = NULL;
                free(current);
                current = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                temp = current->next;
                free(current);
                current = temp;
            }
        }
        else {
            current = current->next;
        }
    }
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printf("Before: ");
    printList(head);
    deleteOdd(&head);
    printf("After: ");
    printList(head);
    return 0;
}
