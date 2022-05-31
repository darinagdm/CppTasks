#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#define N 100
using namespace std;

int main() {
    unsigned long long *arr=new unsigned long long[N];
    const char* finput="inp.txt";
    ifstream file_1(finput);
    int x=0;
    
    while (!file_1.eof()) {
        file_1>>arr[x];
        x++;
    }
    
    file_1.close();
    for (int i=0; i<x; i++) {
        cout<<fixed<<setprecision(3)<<sqrt(arr[x-i-1])<<endl;
    }

    return 0;
}
