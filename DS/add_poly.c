#include<stdio.h>
#include<stdlib.h>

struct poly{
    int coef;
    int expo;
}p1[10],p2[10],p3[10];

int main(){
    int t1, t2, t3, i, j, k;
    setbuf(stdout, NULL);

    printf("\nFIRST POLYNOMIAL\n");
    printf("ENTER THE NO. OF TERMS OF 1ST POLY: ");
    scanf("%d",&t1);

    printf("\nENTER THE COEFF & EXPO IN DESCENDING ORDER\n");
    for(i = 0; i <  t1; i++){
        printf("ENTER THE COEF: ");
        scanf("%d",&p1[i].coef);

        printf("ENTER THE EXPO: ");
        scanf("%d",&p1[i].expo);
    }

    printf("\nSECOND POLYNOMIAL\n");
    printf("ENTER THE NO. OF TERMS OF 2ND POLY: ");
    scanf("%d",&t2);

    printf("\nENTER THE COEFF & EXPO IN DESCENDING ORDER\n");
    for(i = 0; i <  t2; i++){
        printf("ENTER THE COEF: ");
        scanf("%d",&p2[i].coef);

        printf("ENTER THE EXPO: ");
        scanf("%d",&p2[i].expo);
    }

    i = 0;
    j = 0;
    k = 0;

    while(i < t1 && j < t2){
        if(p1[i].expo == p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coef = p1[i].coef + p2[j].coef;
            
            i += 1;
            j += 1;
            k += 1;
        }

        else if(p1[i].expo > p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coef = p1[i].coef;

            i += 1;
            k += 1;
        }

        else{
            p3[k].expo = p2[j].expo;
            p3[k].expo = p2[j].coef;

            j += 1;
            k += 1;
        }
    }

    while(i < t1){
        p3[k].expo = p1[i].expo;
        p3[k].coef = p1[i].coef;

        i += 1;
        k += 1;
    }

    while(j < t2){
        p3[k].expo = p2[j].expo;
        p3[k].coef = p3[j].coef;

        j += 1;
        k += 1;
    }

    printf("\n");

    for(i = 0; i < k-1; i++){
        printf("%d(x^%d)+",p3[i].coef,p3[i].expo);
    }
    printf("%d(x^%d)",p3[k-1].coef,p3[k-1].expo);

    printf("\n");


    return 0;
}