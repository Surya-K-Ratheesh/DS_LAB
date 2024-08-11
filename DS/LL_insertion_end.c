#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LlTraversal(struct Node *ptr);

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    struct Node * p = head;

    ptr -> data = data;

    while(p -> next != NULL){
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

int main(){
    int data;
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));
    fourth = (struct Node *) malloc (sizeof(struct Node));

    head -> data = 7;
    head -> next = second;

    second -> data = 11;
    second -> next = third;

    third -> data = 66;
    third -> next = fourth;

    fourth -> data = 77;
    fourth -> next = NULL;

    printf("Linked List b4 inserttion\n");
    LlTraversal(head);

    printf("Enter an element: ");
    scanf("%d",&data);
    printf("\nLinked list after inserttion\n");

    head = insertAtEnd(head, data);

    LlTraversal(head);

    return 0;
}

void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}