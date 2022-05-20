#include <stdio.h>
#include <math.h>
#define N 3

double sum_arr(double mas[N]){
    double sum=0.0;
    for(int i=0;i<N;i++){
        if(mas[i]>M_E){
            sum+=mas[i];
        }
    }
    return sum;
}

int main(){
    double mas[N];
    for(int i=0;i<N;i++){
        printf("mas[%d]=", i);
        scanf("%lf",&mas[i]);
    }
    printf("Sum=%lf",sum_arr(mas));
}
