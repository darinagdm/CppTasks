#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    scanf("%d",&x);
    int x1 = (int) (x/100);
    int x2 = (int) (x - x1*100)/10;
    int x3 = (int) (x - x1*100 - x2*10);
    if(x1!=x2 && x1!=x3 && x2!=x3)
    {
        int y;
        y = x1*100 + x2*10 + x3;
        printf("%d\n",y);
        y = x1*100 + x3*10 + x2;
        printf("%d\n",y);
        y = x2*100 + x1*10 + x3;
        printf("%d\n",y);
        y = x2*100 + x3*10 + x1;
        printf("%d\n",y);
        y = x3*100 + x2*10 + x1;
        printf("%d\n",y);
        y = x3*100 + x1*10 + x2;
        printf("%d\n",y);
    }  
    else
    {
        printf("Числа не різні.");
    }
}
