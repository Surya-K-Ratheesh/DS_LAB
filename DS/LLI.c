#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * insertAtIndex(struct node *head);
struct node * insertAtBegin(struct node *head);
struct node * insertAtEnd(struct node * head);
void LlTraversal(struct node *ptr);

int main(){
    int data, index, ch;

    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    LlTraversal(head);

    while(ch != 4){
        printf("\n1.Insert at front \n2.Insert at Rear \n3.Insert at Index \n4.Exit \n");
        printf("Enter a choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : 
                struct node *new_head = (struct node *)malloc(sizeof(struct node)); 
                new_head = insertAtBegin(head);
                LlTraversal(new_head);

                break;

            case 2 :     
                head = insertAtEnd(head);
                LlTraversal(head);

                break;

            case 3 :   
                head = insertAtIndex(head);
                LlTraversal(head);

                break;

            case 4 : printf("\n EXITTED \n");
                break;

            default : printf("\nEnter a valid choice\n");            
        }
    }

    return 0;
}

struct node * insertAtIndex(struct node *head){
    int data, index;
    printf("Enter the element: ");
    scanf("%d",&data);

    printf("Enter the index: ");
    scanf("%d",&index);

    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0; 

    while(i != index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node * insertAtBegin(struct node *head){
    int data;
    printf("Enter the element: ");
    scanf("%d",&data);

    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct node * insertAtEnd(struct node * head){
    int data;
    printf("Enter the element: ");
    scanf("%d",&data);


    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;

    ptr->data = data;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

void LlTraversal(struct node *ptr){
    while(ptr != NULL){
        printf("Element is %d \n",ptr->data);
        ptr = ptr->next;
    }
}
