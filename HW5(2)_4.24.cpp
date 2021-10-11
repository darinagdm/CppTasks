#include <iostream>
 
using namespace std;
 
int main()
{
    int i=0,a=0,k;
    cin>>k;
    while (k>0)
    {
        if(k%10!=0&&k%10!=5)
        {
            a*=10;
            a+=k%10;
        }
        k/=10;
    }
     while (a>0)
    {
       cout<<a%10;
        a/=10;
    }
    return 0;
}
