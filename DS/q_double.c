#include<stdio.h>

int f = -1, r =-1, q[20], item;

void insert_front(int size);
void insert_rear(int size);
void delete_front(int size);
void delete_rear(int size);
void display(int size);

int main(){
    int ch, size;

    printf("Enter size of the array: ");
    scanf("%d",&size);

    while(ch != 6){
        printf("\n1. Insert Rear \n2. Delete Rear \n3. Insert Front \n4. Delete Front \n5. Display \n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : insert_rear(size);
                break;

            case 2 : delete_rear(size);
                break;

            case 3 : insert_front(size);
                break;

            case 4 : delete_front(size);
                break;

            case 5 : display(size);
                break;

            case 6 : printf("\nExitted\n");
                break;

            default : printf("\nEnter valid choice\n");
        }
    }

    return 0;
}

void insert_rear(int size){
    if((f == 0)&&(r == size-1)||(f == r+1)){
        printf("\nOVERFLOW\n");
    }

    else if(f == -1 && r == -1){
        printf("Enter the element: ");
        scanf("%d",&item);
        f = 0;
        r = 0;
        q[r] = item;
    }

    else if(r == size - 1){
        printf("Enter the element: ");
        scanf("%d",&item);
        r = 0;
        q[r] = item;
    }

    else{
        printf("Enter the element: ");
        scanf("%d",&item);
        r += 1;
        q[r] = item;
    }
}

void delete_rear(int size){
    if (f == -1 && r == -1){
        printf("\nUNDERFLOW\n");
    }

    else if(f == r){
        item = q[r];
        printf("\nDeleted item is %d \n",item);
        f = -1;
        r = -1;
    }

    else if(r == 0){
        q[r] = item;
        printf("Deleted item is %d",item);
        r = size-1;
    }

    else{
        q[r] = item;
        printf("Deleted item is %d",item);
        r -= 1;
    }

}

void insert_front(int size){
    if((f == 0)&&(r == size-1)||(f == r+1)){
        printf("\nOVERFLOW\n");
    }

    else if(f == -1 && r == -1){
        printf("Enter the element: ");
        scanf("%d",&item);
        f = 0;
        r = 0;
        q[f] = item;
    }

    else if(f == 0){
        printf("Enter the element: ");
        scanf("%d",&item);
        f = size-1;
        q[f] = item;
    }

    else{
        printf("Enter the element: ");
        scanf("%d",&item);
        f -= 1;
        q[f] = item;
    }
}

void delete_front(int size){
    if (f == -1 && r == -1){
        printf("\nUNDERFLOW\n");
    }

    else if(f == r){
        item = q[f];
        printf("\nDeleted item is %d \n",item);
        f = -1;
        r = -1;
    }

    else if(f == size-1){
        q[f] = item;
        printf("Deleted item is %d",item);
        f = 0;
    }

    else{
        q[f] = item;
        printf("Deleted item is %d",item);
        f += 1;
    }
}

void display(int size){
    int i = f;
    printf("Elements in deque are: \n");
    while(i != r){
        printf("%d ",q[i]);
        i = (i+1)%size;
    }
    printf("%d",q[r]);
    printf("\n");
}

