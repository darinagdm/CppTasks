#include <iostream>
#include <math.h>

using namespace std;

double sReLu(double tl,double tr,double al,double ar,double x){
    if(x<=tl){
        return tl+al*(x-tl);
    }
    else if(x>tl && x<tr){
        return 0;
    }
    else{
        return tr+ar*(x-tr);
    }
}

double sReLu_derivative(double tl,double tr,double al,double ar,double x){
    if(x<=tl)
    {
        return al;
    }
    else if(x>tl && x<tr){
        return 0;
    }
    else{
        return ar;
    }
}

int main()
{
    double tl, tr, al, ar, x;
    printf("tl= tr= al= ar= x=\n");
    scanf("%lf %lf %lf %lf %lf", &tl, &tr, &al, &ar, &x);
    double func1,func2;
    func1 = sReLu(tl,tr,al,ar,x);
    func2 = sReLu_derivative(tl,tr,al,ar,x);
    printf("func = %lf, func derivative = %lf",func1,func2);
}
