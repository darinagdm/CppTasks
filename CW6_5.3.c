#include <stdio.h> 
#include <math.h> 
 
int func(int n){ 
    int i = 1; 
    while (n > 1) { 
        if (n % 2 == 0){ 
            n = n / 2; 
            } else n = 3*n + 1; 
        i++; 
        if (i == 1000) break; 
    } 
    return i - 1; 
} 
 
 
int main(){ 
    unsigned n, max_n, i=0, max_i=0; 
    for (n=2; n<1000; n++){ 
        i = func(n); 
        if (i>max_i) { 
            max_i = i; 
            max_n = n; 
        } 
    } 
    printf("\nMax number of iterations is %d with number %d", max_i, max_n); 
}
