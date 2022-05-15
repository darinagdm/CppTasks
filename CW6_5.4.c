#include <stdio.h> 
 
int main(){ 
    unsigned n, i, fact = 1; 
    double p_n = 1; 
    printf("n = "); 
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) { 
        fact *= i; 
        p_n *= 1 + 1.0 / fact; 
    } 
    printf("P(n) = %lf", p_n); 
}
