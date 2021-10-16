#include <stdio.h>
#include <stdlib.h>

typedef struct Polynome10{
    unsigned n;
    double a[10];
} Polynome10;

typedef struct Polynome{
    unsigned n;
    double* a;
} Polynome;

int inputPolynome(Polynome* p){
    printf("n=");
    scanf("%u",&p->n);
    p->a = (double*) malloc((p->n+1) * sizeof(*(p->a)));
    if(!(p->a)){
        printf("cannot allocate memory for polynome");
        return -1;
    }
    for(unsigned i=0;i<=p->n;++i){
        printf("a[%u]=",i);
        scanf("%lf",&(p->a[i]));
    }
    return 0;
}

void printPolynome(const Polynome* p){
    printf("P=");
    for(unsigned i=p->n; i>0;i--){
        printf("%g * x^%u + ",p->a[i],i);
    }
    printf("%g\n",p->a[0]);
}

void deletePolynome(Polynome* p){
    free(p->a);
}

int main(){
    Polynome10 p1;
    p1.n=3;
    p1.a[0]=1;
    
    Polynome p2;
    inputPolynome(&p2);
    printPolynome(&p2);
    
    deletePolynome(&p2);
}
