#include<stdio.h>
#include<stdlib.h>

int stack[50], d, a, i , n, item, top = -1, ch;
void push();
void pop();
void display();

int main(){
    printf("ENTER THE SIZE OF THE STACK: ");
    scanf("%d",&n);

    while(ch != 4){
        printf("\n\t\t********MENU********\n");
        printf("\n1. PUSH \n2.POP \n3.DISPLAY \n4.EXIT \n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : push();
                break;

            case 2 : pop();
                break;

            case 3 : display();
                break;

            case 4 : printf("\nEXITTED\n");
                break;

            default : printf("\nENTER A VALID CHOICE\n");
        }
    }

    return 0;
}

void push(){
    if(top == n-1){
        printf("\nOVERFLOW: STACK IS FULL\n");
    }

    else{
        printf("ENTER THE NO. TO BE INSERTED: ");
        scanf("%d",&item);
        top += 1;
        stack[top] = item;
        printf("\nINSERTION SUCCESSFUL\n");
    }
}

void pop(){
    if(top == -1){
        printf("\nUNDERFLOW: STACK IS EMPTY\n");
    }

    else{
        item = stack[top];
        printf("\nDELETED ELEMENT: %d\n",item);
        top -= 1;
    }
}

void display(){
    if(top == -1){
        printf("\nUNDERFLOW: STACK IS EMPTY\n");
    }

    else{
        printf("\nELEMENTS IN STACK\n");
        for(i = top; i >= 0; i--){
            printf("%d \n",stack[i]);
        }
    }
}