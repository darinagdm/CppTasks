#include <stdio.h>
#define N 5

int print0dds(unsigned mas[],size_t size){
    unsigned sum1=0,sum2=0;
    
    for(size_t i=0;i<size;i++){
        if(mas[i]%2){
            sum2+=mas[i];
        }
        else{
            sum1+=mas[i];
        }
    }
    
    printf("Sum of odds: %u\nSum of evens: %u",sum1,sum2);
    return 0;
}


int main(){
    unsigned mas[N];
    
    for(size_t i=0;i<N;i++){
        printf("mas[%lu]=",i);
        scanf("%u",&mas[i]);
    }
    
    print0dds(mas,N);
}
