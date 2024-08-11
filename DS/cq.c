#include<stdio.h>
#include<stdlib.h>

void enq(int *size);
void deq(int *size);
void disp();

int f = 0, r = 0;
int queue[10], item;

int main(){
    int size, ch;

    printf("ENTER SIZE OF THE ARRAY: ");
    scanf("%d",&size);

    while(ch != 4){
        printf("\n********MENU********\n");
        printf("\n1. INSERT \n2. DELETE \n3. DISPLAY \n4. EXIT \n");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch){
            case 1 : enq(&size);
                break;

            case 2 : deq(&size);
                break;

            case 3 : disp();
                break;  

            case 4 : printf("\nEXITTED\n");
                break;

            default : printf("\nENTER A VALID CHOICE\n");
        }
    }

    return 0;
}

void enq(int *size){
    if((r+1)%(*size) == f){
        printf("\nOVERFLOW: QUEUE IS FULL\n");
    }

    else if(f == r == -1){
        printf("ENTER AN ELEMENT: ");
        scanf("%d",&item);

        f = 0;
        r = 0;
        queue[r] = item;
    }

    else{
        printf("ENTER AN ELEMENT: ");
        scanf("%d",&item);

        r = (r+1)%(*size);
        queue[r] = item;
    }
}

void deq(int *size){
    if(f == r == -1){
        printf("\nUNDERFLOW: QUEUE IS EMPTY\n");
    }

    else if(f == r){
        item = queue[r];
        printf("\nDELETED ELEMENT IS %d\n",item);

        f = -1;
        r = -1;
    }

    else{
        item = queue[r];
        printf("\nDELETED ELEMENT IS %d\n",item);

        f = (f+1)%(*size);
    }
}

void disp(){
    if(f == r == -1){
        printf("\nQUEUE IS EMPTY\n");
    }

    else{
        printf("\nELEMENTS IN ARRAY\n");
        for(int i = f+1; i <= r; i++){
            printf("%d ",queue[i]);
        }
    }
}