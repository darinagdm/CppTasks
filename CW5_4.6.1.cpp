#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    double pr,p;
    std::cout<<"n=";
    std::cin>>n;
    p=0;
    pr=sqrt(2);
    for(int i=1; i<n; i++){
        p=sqrt(2+pr);
        pr=p;
    }
    std::cout<<pr;
}
