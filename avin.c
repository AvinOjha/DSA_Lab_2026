#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node *next;
};

// Insert node at the end
void insert(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp == NULL) {
        return;
    }

    // If first node contains the value
    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display linked list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Linked List:\n");
    display(head);

    deleteNode(&head, 20);

    printf("After deleting 20:\n");
    display(head);

    return 0;
}
