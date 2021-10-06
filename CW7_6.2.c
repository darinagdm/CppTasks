#include <stdio.h>

int main()
{
    unsigned N;
    unsigned k;
    printf("N,k: ");
    scanf("%u",&N);
    scanf("%u",&k);
    N = N | (1<<k);
    printf("M=%u",N);
}
