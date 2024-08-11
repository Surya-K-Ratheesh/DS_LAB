#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * insertatBegin(struct Node *head, int data);
void LlTraversal(struct Node *ptr);

int main(){

    int data;
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory for nodes in the linked list in heap.
    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));
    fourth = (struct Node *) malloc (sizeof(struct Node));

    // Link 1st and 2nd node
    head -> data = 7;
    head -> next = second;
    head -> prev = NULL; 

    // Link 2nd and 3rd node
    second -> data = 11;
    second -> next = third;
    second -> prev = head;

    // Link 3rd and 4th node
    third -> data = 66;
    third -> next = fourth;
    third -> prev = third;

    // Terminate the list at 4th node
    fourth -> data = 77;
    fourth -> next = NULL;
    fourth -> prev = third;

    printf("\n BEFORE INSERTION \n");
    LlTraversal(head);

    printf("\n");

    printf("Enter the data to be inserted: ");
    scanf("%d",&data);

    struct node * newhead;
    newhead = (struct Node *)malloc(sizeof(struct Node));

    newhead = insertatBegin(head, data);
    LlTraversal(newhead);


    return 0;
}

struct Node * insertatBegin(struct Node *head, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;

    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }

    else{
        newNode->next = head;
        head = newNode;
    }

    printf("\n INSERTION SUCCESSFUL \n");

    return newNode;
}

void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr->data);
        ptr = ptr->next;
    }
}