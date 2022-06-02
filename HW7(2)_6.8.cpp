#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t m,j;
    int16_t k;
    cout<<"m-->";
    cin>>m;
    cout<<bitset<16>(m)<<endl;
    cout<<"j-->";
    cin>>j;
    m=~m;
    k=1<<j; 
    //cout<<bitset<32>(k)<<endl;
    m=m|k;
    m=~m;
    cout<<bitset<16>(m)<<endl;
    cout<<m<<endl;
    
    return 0;
}
