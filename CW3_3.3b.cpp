#include <stdio.h> 
#include <cmath> 
int main() 
{ 
    long long int a,b,c; 
    scanf("%lld, %lld, %lld",&a,&b,&c); 
    printf("b)\n"); 
    if (abs(a)<pow(2,21) && abs(b)<pow(2,21) && abs(c)<pow(2,21)) 
        printf("%lld",a*b*c); 
    else 
        printf("Condition rejected\n"); 
    return 0; 
}
