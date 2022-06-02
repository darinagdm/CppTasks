#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a,b,c;
    printf("ax^2 + bx + c = 0\n");
    printf("a b c\n");
    double res,dis;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(fabs(a)<0.000001)
    {
        res = 1;
    }
    else
    {
        dis = b*b - 4*a*c;
        if(dis<0.0)
        {
            res = 0;
        }else if(fabs(dis)<0.000001)
        {
            res = 1;
        }else
        {
            res = 2;
        }
    }
    printf("Рішень = %lf\n",res);
    
    printf("ax^2 + bx + c = 0\n");
    printf("a b c\n");
    double res1,dis1,x1,x2;
    if(fabs(a)<0.000001)
    {
        x1 = (-1)*c/b;
        if(x1>0.0)
        {
            res1 = 2;
        }
        else if(fabs(x1)<0.000001)
        {
            res1 = 1;
        }
        else
        {
            res1 = 0;
        }
    }
    else
    {
        dis1 = b*b - 4*a*c;
        if(dis1<0.0)
        {
            res1 = 0;
        }else if(fabs(dis1)<0.000001)
        {
            x1 = (-1)*b/(2*a);
            if(x1 > 0.0)
            {
                res1 = 2;
            }
            else if(fabs(x1)<0.000001)
            {
                res1 = 1;
            }
            else
            {
                res1 = 0;
            }
        }else
        {
            x1 = ((-1)*b + sqrt(dis1))/(2*a);
            x2 = ((-1)*b - sqrt(dis1))/(2*a);
            if(x1 > 0.0)
            {
                res1 = 2;
            }
            else if(fabs(x1)<0.000001)
            {
                res1 = 1;
            }
            else
            {
                res1 = 0;
            }
            if(x2 > 0.0)
            {
                res1 = res1 + 2;
            }
            else if(fabs(x2)<0.000001)
            {
                res1 = res1 + 1;
            }
            else
            {
                res1 = res1 + 0;
            }
        }
    }
    printf("Рішень = %lf\n",res1);
}
