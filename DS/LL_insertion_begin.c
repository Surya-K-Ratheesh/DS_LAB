#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LlTraversal(struct Node *ptr);

struct Node * insertAtfirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node)); // Created a new node
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}


int main(){
    int data;
    struct Node * head = (struct Node *) malloc (sizeof(struct Node));
    struct Node * second = (struct Node *) malloc (sizeof(struct Node));
    struct Node * third = (struct Node *) malloc (sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc (sizeof(struct Node));

    // Allocate memory for nodes in the linked list in heap.
    // head = (struct Node *) malloc (sizeof(struct Node));
    // second = (struct Node *) malloc (sizeof(struct Node));
    // third = (struct Node *) malloc (sizeof(struct Node));
    // fourth = (struct Node *) malloc (sizeof(struct Node));

    // Link 1st and 2nd node
    head -> data = 7;
    head -> next = second; 

    // Link 2nd and 3rd node
    second -> data = 11;
    second -> next = third;

    // Link 3rd and 4th node
    third -> data = 66;
    third -> next = fourth;

    // Terminate the list at 4th node
    fourth -> data = 77;
    fourth -> next = NULL; 


    LlTraversal(head);
    printf("\n");

    printf("Enter an element: ");
    scanf("%d", &data);

    struct Node * new_head;
    new_head = (struct Node *) malloc (sizeof(struct Node));

    new_head = insertAtfirst(head, data);
    LlTraversal(new_head);

    return 0;
}


void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}