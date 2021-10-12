#include <stdio.h> 
#include <math.h> 
 
int main() { 
    float x, y = 0.0; 
    int n, i; 
    printf("x = "); 
    scanf("%f", &x); 
    printf("n = "); 
    scanf("%d", &n);
    
    for(i=0; i<=n; i++){ 
        y += pow(x, i); 
    } 
    printf("y = %g", y); 
}
