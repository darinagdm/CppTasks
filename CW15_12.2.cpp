#include <iostream>
#include <cstdlib>
#include <string>
//using namespace std;

int main() {
    char str[10];
    unsigned a;
    unsigned long long sum=0L;
    std::cout << "Enter:\n";
    unsigned n=0;
    
    unsigned mas[1000];
    
    while(std::cin.get(str, 10)){
        std::cout<<str<<","<<std::endl;
        std::string::size_type sz;
        a = std::stoul(str,&sz);
        
        mas[n] = a;
        n++;
        sum += a;
    }
    std::cout<<"s="<<sum<<"\n";
}
