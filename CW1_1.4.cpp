#include <iostream>
#include <string>
#include <cmath>

int main()
{
    double m1, m2, r;
    scanf("%lf",&m1);
    scanf("%lf",&m2);
    scanf("%lf",&r);
    double lambda = 6.673*pow(10,-11);
    double f = (lambda*m1*m2)/pow(r,2);
    printf("%lf",f);
}
