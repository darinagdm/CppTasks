#include <iostream>
using namespace std;
 
long double factorial(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * factorial(n - 2);
}
 
int main()
{
    int n;
    
        cout << "n = ";
        cin >> n;
 
        if (n < 0)
        {
            n = -n;
        }
        cout << factorial(n)<< endl;
        return 0;
}
