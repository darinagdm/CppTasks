#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    printf("Без функцій:\n");
    double x;
    scanf("%lf",&x);
    int a,xmax,xmin;
    double b;
    if(x>=0)
    {
        a = (int) x;
        b = x - a;
        xmax = a+1;
        xmin = x-b;
    }
    else
    {
        a = (int) x - 1;
        xmax = a+1;
        xmin = a;
        b = x - a;
    }
    int c;
    if(b>=0.4444449)
    {
        c = xmax;
    }
    else
    {
        c = xmin;
    }
    printf("ціла частина = %d\n",a);
    printf("дробова частина = %lf\n",b);
    printf("найменше більше х = %d\n",xmax);
    printf("найбільше менше х = %d\n",xmin);
    printf("округлене = %d\n",c);
    
    printf("З функціями:\n");
    int xmax1 = ceil(x);
    int xmin1 = floor(x);
    int c1 = round(x);
    printf("ціла частина = %d\n",a);
    printf("дробова частина = %lf\n",b);
    printf("найменше більше х = %d\n",xmax1);
    printf("найбільше менше х = %d\n",xmin1);
    printf("округлене = %d",c1);
}
