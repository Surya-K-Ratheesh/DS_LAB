#include<stdio.h>

int stack[50], d, a, i, n, item, top = -1, ch;
void push();
void pop();
void display();

int main(){
    printf("Enter the size of array: ");
    scanf("%d", &n);

    while(ch != 4){
        printf("1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : push();
                break;

            case 2 : pop();
                break;

            case 3 : display();
                break;

            case 4 : printf("Exitting \n");
                break;

            default : printf("Enter a Valid choice \n");
        }
    }

    return 0;
}

void push(){
    if (top == n-1){
        printf("Stack is full \n");
    }

    else{
        printf("Enter the no. to be inserted: ");
        scanf("%d", &a);
        top += 1;
        stack[top] = a;
    }
}

void pop(){
    if (top == -1){
        printf("Stack is Empty \n");
    }

    else{
        item = stack[top];
        printf("Element to be deleted is %d \n", item);
        top -= 1;
    }
}

void display(){
    if (top == -1){
        printf("Stack is Empty \n");
    }

    else{
        printf("Elemnts in Stack \n");
        for(i = top; i >= 0; i--){
            d = stack[i];
            printf("%d \n", d);
        }
    }
}