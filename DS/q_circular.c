#include<stdio.h>
#include<stdlib.h>

void enq(int *size);
void deq(int *size);
void disp();

int f = 0, r = 0;
int queue[10],item;

int main(){
    int size;
    int ch;
    printf("Enter Size of array: ");
    scanf("%d",&size);

    while(ch != 4){
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \n");
        printf("Enter Your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : enq(&size);
                break;

            case 2 : deq(&size);
                break;

            case 3 : disp();
                break;

            case 4 : printf("\nExitted\n");
                break;

            default : printf("Hi \n");
        }
    }

    return 0;

}

void enq(int *size){
    if((r+1)%(*size) == f){
        printf("OVERFLOW");
    }
    else if(f == r == -1){
        printf("Enter an element: ");
        scanf("%d",&item);
        f = 0;
        r = 0;
        queue[r] = item;
    }
    else{
        printf("Enter an element: ");
        scanf("%d",&item);

        r = (r+1)%(*size);
        queue[r] = item;
    }
}

void deq(int *size){
    if(f == r == -1){
        printf("\nQueue is Empty\n");
    }

    else if(f == r){
        item =  queue[r];
        printf("\nThe deleted item is %d \n",item);
        f = -1;
        r = -1;
    }

    else{
        item = queue[f];
        printf("\nThe deleted item is %d \n",item);
        f = (f+1)%(*size);
    }
}

void disp(){
    if(f == r == -1){
        printf("\nQueue is Empty\n");
    }

    else{
        for(int i = f+1; i <= r; i++){
            printf("%d ", queue[i]);
        }
    }
}