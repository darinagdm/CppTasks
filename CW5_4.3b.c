#include <stdio.h> 
#include <math.h> 
 
int main(){ 
    float x, y, f = 1; 
    int n, i; 
    printf("x = "); 
    scanf("%f", &x); 
    printf("y = "); 
    scanf("%f", &y); 
    printf("n = "); 
    scanf("%d", &n);
    
    for (i=1; i<=n; i++){ 
        f += pow(x, pow(2,i))*pow(y,i); 
    } 
    printf("y = %g", f); 
}
