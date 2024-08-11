#include<stdio.h>

int main(){
    int a[10], i, n, first, last, mid, search;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elements in the array\n");
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d",&search);

    first = 0;
    last = n-1;
    mid = (first + last)/2;

    while(first < last){
        if(a[mid] == search){
            printf("Element is found at location %d\n",mid+1);
            break;
        }

        else if(a[mid] < search){
            first = mid + 1;
        }

        else{
            last = mid - 1;
        }

        mid = (first + last)/2;
    }

    while(first > last){
        printf("Element not found\n");
    }

    return 0;
}