#include <iostream>

bool findOccurrence(int num,int dig){
    int rem, cnt;
    cnt=0;
    
    while(num>0){
        rem=num%10;
        if(rem==dig){
            cnt++;
        }
        num/=10;
    }    
    
    return (cnt>=1);
}
  
int main(){
    std::cout<<"Введіть число: ";
    int num;
    std::cin>>num;
    
    std::cout<<"Введіть цифру для пошуку: ";
    int digit;
    std::cin>>digit;
    
    if(findOccurrence(num,digit)){
        std::cout<<"Дана цифра входить у число";
    }
    else{
        std::cout<<"Дана цифра не входить у число";
    }
}
