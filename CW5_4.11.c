#include <stdio.h> 
#include <math.h> 
 
int main(){ 
    double sum=0, geom_aver=1; 
    int num=1, quant=0; 
    
    while (num >= 1) { 
        printf("a[%d] = ", quant); 
        scanf("%d", &num); 
        if (num == 0) break; 
        sum += num; 
        geom_aver *= num; 
        quant++; 
    } 
    
    double aver = sum/quant; 
    geom_aver = pow(geom_aver, (double) 1/quant); 
    printf("Average: %g \nGeometric average: %g", aver, geom_aver); 
}
