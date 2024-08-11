#include<stdio.h>

int c[10][10], i, j, m, n, k, count=0, a[10][10];

int main(){
    printf("Enter rows and columns: ");
    scanf("%d %d",&m, &n);

    printf("Enter the matrix: ");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
        }
    }

    k = 1;
    for(i = 0;i < m; i++){
        for(j = 0; j < n; j++){
            if(a[i][j] != 0){
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = a[i][j];
                k += 1;
                count += 1;
            }
        }
    }

    c[0][0] = m;
    c[0][1] = n;
    c[0][2] = count;

    printf("\nTriple Representation is \n");

    for(i = 0;i <= c[0][2]; i++){
        for(j = 0; j < n; j++){
            printf("%d",c[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}