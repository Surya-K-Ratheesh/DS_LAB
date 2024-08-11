#include <stdio.h>

struct poly{
    int coef;
    int exp;
} p[30];

void printpoly(int kf, int kl);
void polyadd(int af, int al, int bf, int bl, int cl);
int comp(int x, int y);
int result(int co, int ex, int cl);

int main(){
    int af = 0, al = 0, bf, bl, cf, cl, i, m, n;
    printf("\nEnter the number of terms for the first and second polynomial:\n");
    scanf("%d %d", &m, &n);

    printf("Enter coefficients and exponents for the first polynomial:\n");
    for (i = 0; i < m; i++){
        scanf("%d %d", &p[i].coef, &p[i].exp);
        al = al + 1;
    }
    al = al - 1;
    bf = al + 1;
    bl = bf;

    printf("Enter coefficients and exponents for the second polynomial:\n");
    for (i = bf; i < (bf + n); i++){
        scanf("%d %d", &p[i].coef, &p[i].exp);
        bl = bl + 1;
    }
    
    bl = bl - 1;
    cf = bl + 1;
    cl = cf;

    polyadd(af, al, bf, bl, cf);
    printf("\nResultant polynomial is:\n");
    printpoly(cf, cl);

    return 0; // You should return 0 to indicate a successful execution.
}

void polyadd(int af, int al, int bf, int bl, int cl)
{
    int w = af, q = bf, x, s;
    while (w <= al && q <= bl){
        x = comp(p[w].exp, p[q].exp);
        switch (x){
        case 0:
            s = p[w].coef + p[q].coef;
            cl = result(s, p[w].exp, cl);
            w = w + 1;
            q = q + 1;
            break;
        case 1:
            cl = result(p[w].coef, p[w].exp, cl);
            w = w + 1;
            break;
        case 2:
            cl = result(p[q].coef, p[q].exp, cl);
            q = q + 1;
            break;
        }
    }
    while (w <= al){
        cl = result(p[w].coef, p[w].exp, cl);
        w = w + 1;
    }
    while (q <= bl){
        cl = result(p[q].coef, p[q].exp, cl);
        q = q + 1;
    }
}

int comp(int x, int y)
{
    if (x == y){
        return 0;
    }
    else if (x > y){
        return 1;
    }
    else{
        return 2;
    }
}

int result(int co, int ex, int cl)
{
    p[cl].coef = co;
    p[cl].exp = ex;
    cl = cl + 1;
    return cl; // Return the updated 'cl' value.
}

void printpoly(int kf, int kl)
{
    int i;
    for (i = kf; i < kl; i++){
        printf("%d %d\n", p[i].coef, p[i].exp);
    }
}
