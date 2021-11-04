#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    double res = pow(x, y);
    cout << res << endl;
    cout.setf(ios::scientific);
    cout << res;
}
