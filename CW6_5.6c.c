#include <stdio.h> 
 
 
int main(){ 
    double x; 
    int n, i; 
    printf("2n = "); 
    scanf("%d", &n); 
    x = 2; 
    
    for (i = 0; i<n; i++) { 
        x = 1 + i % 2 + 1.0/x; 
    } 
    printf("b_n = %lf", x); 
}
