#include <iostream>
#include <cmath>

float func_a(int n){
    int a1=0,a2=1,ak,b1=1,b2=0,bk,s=0;
    s=3;
    for(int k=3; k<=n; k++){
        bk=b2+a2;
        ak=a2/k+a1*bk;
        s+=pow(2,k)/(ak+bk);
        a1=a2;
        a2=ak;
        b1=b2;
        b2=bk;
    }
    return s;
}

int main(){
    int n;
    std::cout<<"n=";
    std::cin>>n;
    std::cout<<func_a(n);
}
