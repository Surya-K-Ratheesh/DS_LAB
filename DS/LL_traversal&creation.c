#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LlTraversal(struct Node *ptr);

int main(){
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

    return 0;
}

void LlTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}