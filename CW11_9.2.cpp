#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int input(int** a) {
    *a = (int*) malloc(0 * sizeof **a);
    int n = 0;
    if (*a) {
        while (n < 100) {
            int m;
            cin >> m;
            if (m == 0)
                break;
            n++;
            *a = (int*) realloc(*a, n * sizeof **a);
            if (*a == NULL)
                exit(1);
            (*a)[n - 1] = m;
        }
    }
    return n;
}

void print(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ends;
    cout << endl;
}

int full_squares(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double sr = sqrt(a[i]);
        if (sr == floor(sr))
            count++;
    }
    return count;
}

int full_cubes(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double cr = cbrt(a[i]);
        if (cr == floor(cr))
            count++;
    }
    return count;
}

int main() {
    int* a;
    int n = input(&a);
    print(a, n);
    cout << full_squares(a, n) << endl;
    cout << full_cubes(a, n) << endl;
    free(a);
    return 0;
}
