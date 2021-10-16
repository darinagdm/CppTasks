#include <stdio.h>

typedef struct Point{
    double x,y;
} Point;

typedef struct Rectangle{
    Point A;
    Point B;
} Rectangle;

int inputRect(Rectangle * r){
    printf("A(x,y)");
    int d = scanf("%lf %lf",&r->A.x, &r->A.y);
    if(d<2) return 4 -d;
    printf("B(x,y)");
    d += scanf("%lf %lf",&r->B.x, &r->B.y);
    return 4 -d;
}

void printRect(const Rectangle * r){
    printf("(%lf %lf)",r->A.x, r->A.y);
    printf("-(%lf %lf)",r->B.x, r->B.y);
}

int main(){
    Rectangle x;
    inputRect(&x);
    printRect(&x);
}
