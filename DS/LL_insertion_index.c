#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LlTraversal(struct Node *ptr);

struct Node * insertAtIndex(struct Node *head, int data,int index){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i != index-1){
        p = p -> next;
        i++;
    }

    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;

    return head; 
}

int main(){
    int data, index;
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

    LlTraversal(head);

    printf("Enter the data to be entered: ");
    scanf("%d",&data);

    printf("Enter the index: ");
    scanf("%d",&index);

    head = insertAtIndex(head, data, index);

    LlTraversal(head);

    return 0;
}

void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element is %d \n", ptr -> data);
        ptr = ptr -> next;
    }
}