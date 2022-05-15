#include <stdio.h>

int main()
{
    unsigned long long M;
    unsigned j;
    printf("Input M and j:\n");
    scanf("%Lu",&M);
    scanf("%u",&j);
    M = M & ~(1<<j);
    printf("M = %Lu %Lo %Lx", M, M, M);
}
