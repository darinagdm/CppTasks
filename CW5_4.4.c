#include <stdio.h> 
#include <math.h> 
 
int main(){ 
    float x, y = 0; 
    int n, i; 
    printf("x = "); 
    scanf("%f", &x); 
    printf("n = "); 
    scanf("%d", &n); 
    
    for (i=1; i<=n; i++) { 
        y += i*pow(x,i); 
    } 
    printf("y = %g", y); 
}
