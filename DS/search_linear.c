#include<stdio.h>

int main(){
    int a[10], n, i, j, flag = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter The elements: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the no. to be searched: ");
    scanf("%d",&j);

    for(i = 0; i < n; i++){
        if (a[i] == j){
            flag = 1;
            break;
        }
    }

    if (flag == 1){
        printf("%d is found at the position %d \n", j, i+1);
    }

    else{
        printf("%d not found \n",j);
    }

    return 0;
}