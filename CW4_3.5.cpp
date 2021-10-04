#include <iostream>

using namespace std;

int main()
{
    double a,b;
    printf("Введіть два числа через пробіл\n");
    scanf("%lf %lf",&a,&b);
    double max,min;
    if(a>b)
    {
        max = a;
        min = b;
        printf("max = %lf, min = %lf",max,min);
    }
    else if(b>a)
    {
        max = b;
        min = a;
        printf("max = %lf, min = %lf",max,min);
    }
    else
    {
        printf("a=b");
    }
}
