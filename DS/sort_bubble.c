#include<stdio.h>
#include<stdlib.h>

void printArray(int* A,int n);
void bubblesort(int *A, int n);

int main(){
    int A[50], n; 
    
    printf("Enter the size of array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("\nARRAY BEFORE SORTING\n");
    printArray(A, n);

    bubblesort(A, n);

    printf("\nARRAY AFTER SORTING\n");
    printArray(A, n);

    return 0;
}

void printArray(int* A,int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubblesort(int *A, int n){
    int temp;
    for(int i = 0; i < n-1;i++){
        for(int j = 0; j < n-1-i; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}