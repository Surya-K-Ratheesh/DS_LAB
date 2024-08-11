#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue *q);
int isEmpty(struct queue *q);
void enq(struct queue *q);
int deq(struct queue *q);
void disp(struct queue *q);


int main(){
    int ch;
    struct queue q;
    q.size;
    printf("Enter Size of Queue: ");
    scanf("%d",&q.size);
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    while(ch != 4){
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : enq(&q);
                break;

            case 2 : deq(&q);
                break;

            case 3 : disp(&q);
                break;

            case 4 : printf("\nExited\n");
                break;

            default : printf("\nEnter a valid choice!\n");  
        }
    }
    return 0;
}


void enq(struct queue *q){
    int val;
    if(isFull(q)){
        printf("\nThis Queue is full\n");
    }

    else{
        printf("Enter the value to be inserted: ");
        scanf("%d",&val);
        q -> r++;
        q -> arr[q->r] = val;
    }
}

int deq(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("\nQueue is Empty\n");
    }

    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void disp(struct queue *q){
    if(isEmpty(q)){
        printf("\nQueue is Empty\n");
    }

    else{
        for(int i = q->f+1; i <= q->r; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int isFull(struct queue *q){
    if(q -> r == q -> size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q -> r == q -> f){
        return 1;
    }
    return 0;
}