#include<stdio.h>
#include<stdlib.h>

struct poly{
    int coef;
    int exp;
    struct node *next;
};
typedef struct poly NODE;
NODE *start;

void display(NODE *n);
void polyadd(NODE *a,NODE *b);
NODE *readpoly();

int main(){
    NODE *a, *b;
    printf("Enter 1st poly:  ");
    a = readpoly();

    printf("Enter 2nd poly: ");
    b = readpoly();

    polyadd(a,b);

    return 0;
}

NODE *readpoly(){
    int n, i;
    NODE *head, *temp;
    start = NULL;

    printf("Enter the no. of terms: ");
    scanf("%d",&n);

    printf("Enter the coeff and exp: ");
    for(i = 0; i < n; i++){
        head = (NODE*) malloc (sizeof(NODE));
        scanf("%d %d",&head->coef, &head->exp);
        head->next = NULL;

        if (start == NULL){
            start = temp = head; 
        }

        else{
            temp->next = head;
            temp = head;
        }
    }

    return start;
}

void polyadd(NODE *a,NODE *b){
    NODE *p, *q, *s, *temp;
    p = a;
    q = b;
    start = NULL;

    while((p != NULL) && (q != NULL)){
        s = (NODE*) malloc (sizeof(NODE));
        s->next = NULL;

        if (p->exp > q->exp){
            s->coef = p->coef;
            s->exp = p->exp;
            p = p->next;
        }

        else if(p->exp < q->exp){
            s->coef = q->coef;
            s->exp = q->exp;
            q = q->next;
        }

        else{
            s->coef = p->coef + q->coef;
            s->exp = p->exp;
            p = p->next;
            q = q->next;
        }

        if(start == NULL){
            start = temp = s;
        }

        else{
            temp->next = s;
            temp = s;
        }
    }

    while(p != NULL){
        s = (NODE*) malloc (sizeof(NODE));
        s->coef = p->coef;
        s->exp = p->exp;
        s->next = NULL;

        p = p->next;
        temp->next = s;
        temp = s;
    }

    while(q != NULL){
        s = (NODE*) malloc (sizeof(NODE));
        s->coef = q->coef;
        s->exp = q->exp;
        s->next = NULL;

        q = q->next;
        temp->next = s;
        temp = s;
    }

    printf("\nRESULTANT POLYNOMIAL\n");
    display(start);
}