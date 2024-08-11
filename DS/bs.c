#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[20], first, last, mid, i, search, n;

    printf("Enter size of the array: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d",&search);

    first = 0;
    last = n-1;
    mid = (first + last)/2;

    while(first < last){
        if(A[mid] == search){
            printf("Element %d found at %d\n",search ,mid+1);
            break;
        }

        else if(search < A[mid]){
            last = mid - 1;
        }

        else{
            first = mid + 1;
        }
    }

    while(first > last){
        printf("Element not found\n");
    }

    return 0;
}