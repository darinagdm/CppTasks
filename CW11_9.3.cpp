#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int* input(int n) {
    int* a = (int*) calloc(n, sizeof (int));
    if (a == nullptr)
        exit(1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

void print(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ends;
    cout << endl;
}

int* substruct(int* a, int* b, int n) {
    int* c = (int*) calloc(n, sizeof (int));
    if (c == nullptr)
        exit(1);
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    return c;
}

int main() {
    int n;
    cin >> n;
    int* a = input(n);
    int* b = input(n);
    int* c = substruct(a, b, n);
    // print(a, n);
    // print(b, n);
    print(c, n);
    free(a);
    free(b);
    free(c);
    return 0;
}
