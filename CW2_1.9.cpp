#include <iostream>
#include <string>
#include <cmath>

int main()
{
    double a,b,c,d;
    scanf("%lf %lf",&a,&b);
    c = (a+b)/2;
    d = 2/(1/a + 1/b);
    printf("arifm=%f",c);
    printf("\ngarmon=%f",d);
    printf("\narifm=%e",c);
    printf("\ngarmon=%e",d);
}
