#include <stdio.h> 
#include <math.h> 

int main(){ 
    int n, r; 
    printf("n = "); 
    scanf("%d", &n); 
    r = 0; 
    
    while (pow(2, r)<n){ 
        r++; 
    } 
    printf("2^%d > %d", r, n); 
}
