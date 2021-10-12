#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x;
    int n;
    cout<<"Введіть x і n"<<endl;
    cin>>x>>n;
    for(int i=0; i<n; i++){
        x=sin(x);
    }
    cout<<x;
    return 0;
}
