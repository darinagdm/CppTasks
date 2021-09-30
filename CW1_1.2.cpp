#include <iostream>
#include <cmath>

int main() 
{
    float q,w,e,r,t,y;
    q=10e-4;
    w=24.33e5;;
    e=M_PI;
    r=exp(1);
    t=sqrt(5);
    y=log(100);
    printf ("%f\n %f\n %f\n %f\n %f\n %f\n",q,w,e,r,t,y);
    double q1,w1,e1,r1,t1,y1;
    q1=10e-4;
    w1=24.33e5;
    e1=M_PI;
    r1=exp(1);
    t1=sqrt(5);
    y1=log(100);
    printf ("%lf\n %lf\n %lf\n %lf\n %lf\n %lf\n",q1,w1,e1,r1,t1,y1);
    long double q2,w2,e2,r2,t2,y2;
    q2=10e-4;
    w2=24.33e5;
    e2=M_PI;
    r2=exp(1);
    t2=sqrt(5);
    y2=log(100);
    printf ("%Lf\n %Lf\n %Lf\n %Lf\n %Lf\n %Lf\n",q2,w2,e2,r2,t2,y2);
    return 0;
}
