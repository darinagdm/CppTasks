#include <iostream>
#include <string>
using namespace std;

int split(string a, string sep, int n, string w[])
{
    size_t x = 0;
    size_t y = 0;
    
    if(a[a.size() - 1] != ' ')
    {
        a += " ";
    }
    
    while ((y = a.find(sep)) != string::npos && x<n)
    {
        w[x++] = a.substr(0, y);
        a.erase(0, y + sep.length());
    }
    
    return x;
}

int main()
{
    string st = "Have a good day!";
    string sep = " ";
    string w[4];
    
    int z = split(st, sep, 5, w);
    
    for(int i = 0; i < z; i++)
    {
        cout << w[i] << endl;
    }
    
    return 0;
}
