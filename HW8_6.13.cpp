#include <iostream>
#include <bitset>
using namespace std;

void task6_13(){
    uint32_t number;

    cout<<"\n  Task 6.13\nInput 32-bit positive number: ";

    scanf("%d",&number);
    
    if (number<=0) return;

    int count = 0;

    cout<< bitset<32>(number) << endl; 
    
    for (int i=sizeof(number)*8; i>=0; i--){
        count += (number & 1) ? 1 : 0;
        number>>=1;
    }

    printf("Number has %d non-zero bits.\n",count);
}

int main(){
    task6_13();
    return 0;
}
