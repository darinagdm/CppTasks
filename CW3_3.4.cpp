#include <iostream>
#include <cmath>

using namespace std;
uint16_t mult(uint8_t x, uint8_t y)
{
    return x*y;
}

int main()
{
    uint8_t x,y;
    printf("Введіть х та у через пробіл\n: ");
    scanf("%hhu %hhu",&x,&y);
    uint16_t z = mult(x,y);
    printf("z=%hu",z);
}
