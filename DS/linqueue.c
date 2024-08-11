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
    if(rear == maxsize-1){
        printf("\nOVERFLOW: Queue is full\n");
    }

    else{
        printf("Enter an element: ");
        scanf("%d",&item);

        rear += 1;
        queue[rear] = item;
        if(front == -1){
            front += 1;
        }
    }
}

void delete(){
    if(front == -1 || front > rear){
        printf("\nUNDERFLOW: Queue is empty\n");
    }

    else{
        item = queue[front];
        printf("\nItem to be deleted is %d\n",item);
        front += 1;
    }
}

void display(){
    if(front == -1 || front > rear){
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


