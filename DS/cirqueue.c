#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

void insert();
void delete();
void display();

int item;

int front = -1, rear = -1;
int queue[maxsize];

int main(){
    int choice;
    while(choice != 4){
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1 : insert();
                break;

            case 2 : delete();
                break;

            case 3 : display();
                break;

            case 4 : printf("\nExitted \n");
                break;

            default : printf("\nEnter a valid Choice\n");
        }
    }

    return 0;
}

void insert(){
    if((rear+1)%maxsize == front){
        printf("\nOVERFLOW: Queue is full\n");
    }

    else if(front == rear == -1){
        front = 0;
        rear = 0;
        printf("Enter an Element: ");
        scanf("%d",&item);
        queue[rear] = item;
    }

    else{
        rear = (rear+1)%maxsize;
        printf("Enter an Element: ");
        scanf("%d",&item);
        queue[rear] = item;
    }
}

void delete(){
    if(front == rear == -1){
        printf("\nUNDERFLOW: Queue is empty\n");
    }

    else if(front == rear){
        item = queue[front];
        printf("\nItem to be deleted is %d\n",item);
        front = -1;
        rear = -1;
    }

    else{
        item =  queue[front];
        front = (front+1)%maxsize;
    }
}

void display(){
    if(front == rear == -1){
        printf("\nUNDERFLOW: Queue is empty\n");
    }

    else{
        printf("\nElements in Queue: ");
        for(int i = front; i < rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}


