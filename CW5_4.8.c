#include <stdio.h> 
#include <math.h> 
 
 
int main(){ 
    int m, k; 
    printf("m = "); 
    scanf("%d", &m); 
    k = 0; 
    
    while (pow(4, k) <= m) { 
        k++; 
    } 
    k--; 
    printf("4^%d <= %d", k, m); 
}
