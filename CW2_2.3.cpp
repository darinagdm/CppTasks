#include <iostream>
#include <cmath>
using namespace std;

void my_square(double a, double b, double c, double*s) {
    double p = (a + b + c) / 2;
    (*s) = sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double a, b, c, s;
    cin >> a >> b >> c;
    my_square(a, b, c, &s);
    cout << s << endl;
    return 0;
}
