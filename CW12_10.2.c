#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char col;
    unsigned row;
} Field;

int input(Field *x){
    Field res;
    unsigned t;
    printf("col = ");
    scanf("%c",&res.col);
    scanf("%u",&t);
    res.row = t;
    *x = res;
    return 0;
}

void print(const Field x){
    printf("%c:%u\n", x.col, x.row);
}

bool check(Field x, Field y){
    if(x.col == y.col) return true;
    if(x.row == y.row) return true;
    if(x.row - y.row == x.col - y.col) return true;
    return false;
}

int main(){
    Field point;
    Field point_2;
    input(&point);
    input(&point_2);
    print(point);
    print(point_2);
    
    if(check(point, point_2)){
        printf("Ferz hodit");
    }
    return 0;
}
