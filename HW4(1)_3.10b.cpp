#include <iostream>
using namespace std;
 
int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    int k = 0;
    if (x==y && y==z)
        k = 3;
    else if ((x==y && x!=z) || (y==z && x!=y) || (x==z && x!=y))
        k = 2;
    cout <<k <<endl;
    return 0;
}
