#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Declare the head pointer
struct Node* head = NULL;

// Function declarations
void insert_beginning(int value);
void insert_end(int value);
void insert_random(int value, int position);
void delete_beginning();
void delete_end();
void delete_random(int position);
void display();

int main() {
    int choice, value, position;

    while (1) {
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Random Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Random Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_beginning(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &position);
                insert_random(value, position);
                break;

            case 4:
                delete_beginning();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                delete_random(position);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to insert a node at the beginning
void insert_beginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end
void insert_end(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node at a specific position
void insert_random(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

// Function to delete a node from the beginning
void delete_beginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end
void delete_end() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted from the list.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

// Function to delete a node from a specific position
void delete_random(int position) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
