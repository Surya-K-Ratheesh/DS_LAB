#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void LlTraversal(struct Node *ptr);
struct node * insertatEnd(struct Node *head, int data);

int main(){

    int data;
    struct Node * head = (struct Node *) malloc (sizeof(struct Node));
    struct Node * second = (struct Node *) malloc (sizeof(struct Node));
    struct Node * third = (struct Node *) malloc (sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc (sizeof(struct Node));

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

    printf("Linked List b4 inserttion\n");
    LlTraversal(head);

    printf("Enter an element: ");
    scanf("%d",&data);
    printf("\nLinked list after inserttion\n");

    head = insertatEnd(head, data);

    LlTraversal(head);

    return 0;
}

void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("%d \n",ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertatEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));

    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL){
        ptr->prev = NULL;
        head = ptr;
    }

    else{
        struct Node *p = head;

        while(p->next != NULL){
            p = p->next;

            p->next = ptr;
            p->prev = p;
        }
    }

    printf("\nINSERTION SUCCESSFUL\n");

    return head;
}

