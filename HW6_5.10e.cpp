#include <iostream>
#include <cmath>

using namespace std;

int fact(int N){
    if(N < 0){
        return 0;
    }
    if (N == 0){
        return 1;
    }
    else{ 
        return N * fact(N - 1);
    }
}

float func_a(int n){
    int a0=1,ak,s=0;
    for(int k=1; k<=n; k++){
        ak=k*a0+1/k;
        int num = fact(k);
        s+=(pow(2,k)/(num))*ak;
        a0=ak;
    }
    return s;
}

int main(){
    int n;
    std::cout<<"n=";
    std::cin>>n;
    std::cout<<func_a(n);
}
