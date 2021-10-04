#include <stdio.h> 
#include <cmath> 
int main() 
{ 
    long long int a,b,c; 
    scanf("%lld, %lld, %lld",&a,&b,&c); 
    printf("a)\n"); 
    if (abs(a)<pow(2,10) && abs(b)<pow(2,10) && abs(c)<pow(2,10)) 
        printf("%lld",a*b*c); 
    else 
        printf("Condition rejected\n"); 
    return 0; 
}
