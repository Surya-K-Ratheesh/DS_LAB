#include<stdio.h>
#include<stdlib.h>

// void selection(int arr[], int n);

int main(){
    int n, arr[10], i, j, small, temp;

    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter elements into the array: ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    // selection(arr[10],n);

    // int i, j ,small, temp;

    for(i = 0; i < n-1; i++){
        small = i;

        for(j = i+1; j < n; j++){
            if(arr[j] < arr[small]){
                small = j;

                temp = arr[small];
                arr[small] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%d",arr[i]);
        printf("\t");
    }

    return 0;
}

// void selection(int arr[], int n){
//     int i, j ,small, temp;

//     for(i = 0; i < n-1; i++){
//         small = i;

//         for(j = i+1; j < n; j++){
//             if(arr[j] < arr[small]){
//                 small = j;

//                 temp = arr[small];
//                 arr[small] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }

//     for(i = 0; i < n; i++){
//         printf("%d",arr[i]);
//         printf("\t");
//     }
// }