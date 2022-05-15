#include <stdio.h> 
 
 
int main(){ 
    double a, res = 1, i = 2; 
    printf("a="); 
    scanf("%lf", &a); 
    
    while (a>res) { 
        res += 1/i; 
        i++; 
    } 
    
    printf("%lf > %lf", res, a); 
    printf("\nn = %g", i); 
}
