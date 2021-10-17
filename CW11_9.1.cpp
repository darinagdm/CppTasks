#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n > 0) {
        double* a = (double*) calloc(n, sizeof *a);
        if (a) {
            double s = 0;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
                s += a[i] * a[i];
            }
            cout << s << endl;
            free(a);
        }
    }
    return 0;
}
