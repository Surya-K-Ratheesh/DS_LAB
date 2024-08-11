#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *A, int n);
void printArray(int *A, int n);

int main(){
    int n, A[10];

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("\nARRAY BEFORE SORTING\n");
    printArray(A, n);

    selectionSort(A, n);

    printf("\nARRAY AFTER SORTING\n");
    printArray(A, n);

    return 0;
}

void selectionSort(int *A, int n){
    int indexOfMin, temp;
    for(int i = 0; i < n; i++){
        indexOfMin = i;

        for(int j = i+1; j < n; j++){
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}