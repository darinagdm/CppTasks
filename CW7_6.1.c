#include <stdio.h>

int main()
{
    unsigned char n;
    unsigned long long m;
    printf("n=");
    scanf("%hhu",&n);
    m=1<<n;  
    printf("m=%Lu",m);
}
