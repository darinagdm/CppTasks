#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    scanf("%d",&a);
    int a1 = (int) (a/100);
    int a2 = (int) (a - a1*100)/10;
    int a3 = (int) (a - a1*100 - a2*10);
    int sum = a1+a2+a3;
    int back = a3*100 + a2*10 + a1;
    printf("Кількість сотень - %d, десятків - %d, одиниць - %d.\nСума цифр - %d.\nЧисло справа наліво - %d.",a1,a2,a3,sum,back);
}
