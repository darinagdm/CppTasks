#include <stdio.h> 
 
 
int fib(int n){ 
    int res; 
    if(n <= 0) {return 0;} 
    if(n == 1 || n == 2) {return 1;}

    int prev = 1, cur = 1; 
    for (int i = 2; i<n; i++){ 
        res = prev + cur; 
        prev = cur; 
        cur = res; 
    } 
    return res; 
} 
 

int max_prev_fib_numb(int a){ 
    int prev = 1, cur = 1, res, i = 1; 
    
    while (res <= a){ 
        res = prev + cur; 
        prev = cur; 
        cur = res; 
        i++; 
    } 
    return i; 
} 
 
 
int min_greater_fib_numb(int a){ 
    int prev = 1, cur = 1, res, i = 2; 
    
    while (res <= a){ 
        res = prev + cur; 
        prev = cur; 
        cur = res; 
        i++; 
    } 
    return i; 
} 
 
 
int sum_all_fibs_lesser_then(int n){ 
    int prev = 1, cur = 1, fib = 2, res = 2; 
    while (fib <= n){ 
        fib = prev + cur; 
        prev = cur; 
        cur = fib; 
        res += fib; 
    } 
    return res; 
} 
 
 
int main(){ 
    int n; 
    printf("n = "); 
    scanf("%d", &n); 
    printf("Fib(n) = %d", fib(n)); 
    int a; 
    printf("\na = "); 
    scanf("%d", &a); 
    printf("%d", max_prev_fib_numb(a)); 
    int b; 
    printf("\na = "); 
    scanf("%d", &b); 
    printf("%d", min_greater_fib_numb(b)); 
    printf("\nSum of fibs lesser then 1000: %d", sum_all_fibs_lesser_then(1000)); 
}
