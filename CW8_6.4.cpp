#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint32_t n = 0b11101101000110000001100001010101;
    cout << n << endl;
    // 11101101 00011000 00011000 01010101
    cout << bitset<32>(n) << endl;
    uint32_t first8, last8;
    last8 = n >> 24;
    cout << bitset<32>(last8) << endl;
    first8 = n << 24;
    cout << bitset<32>(first8) << endl;
    n = (n >> 8) << 8;
    n = (n << 8) >> 8;
    cout << bitset<32>(n) << endl;
    n = n | last8 | first8;
    // 01010101 00011000 00011000 11101101
    cout << bitset<32>(n) << endl;
    cout << n << endl;
    return 0;
}
