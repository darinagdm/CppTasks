#include <stdio.h> 
 
int main(){ 
    double b; 
    int n, i; 
    printf("n = "); 
    scanf("%d", &n); 
    b = 4*n + 2; 
    
    for (i = 1; i<=n; i++) { 
        b = 4*(n-i) + 2 + 1.0/b; 
    } 
    printf("b(n) = %lf", b); 
}
