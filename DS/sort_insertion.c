#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n);
void insertionSort(int *A, int n);

int main(){
    int n, A[10];

    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("\nARRAY BEEORE SORTING\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("\nARRAY AFTER SORTING\n");
    printArray(A, n);

    return 0;
}

void insertionSort(int *A, int n){
    int key, j;
    //Loop for passes
    for(int i = 1; i <= n-1; i++){
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}