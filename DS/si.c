#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n);
void insertionSort(int *A, int n);

int main(){
    int n, A[10];

    printf("ENTER THE SIZE OF ARRAY: ");
    scanf("%d",&n);

    printf("ENTER THE ELEMENTS: \n");
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("\nARRAY BEFORE SORTING\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("\nARRAY AFTER SORTING\n");
    printArray(A, n);

    return 0;
}

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;

    for(int i = 1; i < n; i++){
        key = A[i];
        j = i-1;

        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}