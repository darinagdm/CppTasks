#include <iostream>

int func(){
    std::cout<<"Введіть n i k: ";
    int n,k;
    std::cin>>n>>k;
    
    std::cout<<"Введіть m: ";
    int m;
    std::cin>>m;
    
    int a;
    if(m%n==0 && m%k==0){
        a=1;
    }
    else{
        a=0;
    }
    return a;
}

int main(){
    int num = func();
    std::cout<<"Результат: "<<num<<std::endl;
}
