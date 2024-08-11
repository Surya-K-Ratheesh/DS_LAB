#include<stdio.h>
#include<stdlib.h>

void printArray(int* A,int n);
void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main(){
    int A[50], n; 
    
    printf("Enter the size of array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("\nARRAY BEFORE SORTING\n");
    printArray(A, n);

    quickSort(A, 0, n-1);

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

void quickSort(int A[], int low, int high){
    int partitionIndex; //Index of Pivot after partition

    if(low < high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1); // Sort Left sub array
        quickSort(A, partitionIndex+1, high); // Sort Right Sub array
    }
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(A[i] <= pivot){
            i++;
        }

        while(A[j] > pivot){
            j--;
        }

        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i < j);

    //Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}