#include <iostream>

using namespace std;

int main(){
    int n;
    float b;
    cin>>n>>b;
    float a=b;
    for (int i=0; i<n; i++){
        a = b + 1/a;
    }
    cout << a;
    return 0;
}
