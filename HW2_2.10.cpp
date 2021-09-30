#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c;
    double a1,b1,c1;
    printf("Введіть довжини сторін через пробіл:\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    a1 = acos((-1)*(a*a - b*b - c*c)/(2*b*c));
    b1 = acos((-1)*(b*b - a*a - c*c)/(2*a*c));
    c1 = acos((-1)*(c*c - b*b - a*a)/(2*b*a));
    printf("У радіанах: alpha = %lf ,beta = %lf, gamma = %lf\n",a1,b1,c1);
    double a2 = a1*180/M_PI;
    double b2 = b1*180/M_PI;
    double c2 = c1*180/M_PI;
    printf("У градусах: alpha = %lf ,beta = %lf, gamma = %lf\n",a2,b2,c2);
}
