#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    double x, e;
    cin>>x>>e;
    
    double result=1;
    double component=1;
    
    for (int i=1; abs(component)>=e; i++)
    {
        component*=(x/i);
        result+=component;
    }
    cout<<result<<endl;
    return 0;
}
