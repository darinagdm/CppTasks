#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int* create_matrix(int n) {
    int* a = (int*) calloc(n * n, sizeof *a);
    if (a == nullptr)
        exit(1);
    return a;
}

void delete_matrix(int* a) {
    free(a);
}

int* input_matrix(int n) {
    int* a = create_matrix(n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        for (int j = 0; j < n; j++) {
            cin >> a[i * n + j];
        }
    }
    return a;
}

void print_matrix(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i * n + j] << ends;
        }
        cout << endl;
    }
    cout << endl;
}

int* product_matrix(int* a, int* b, int n) {
    int* c = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                c[i * n + j] += a[i * n + k] * b[k * n + j];
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    int* a = input_matrix(n);
    int* b = input_matrix(n);
    int* c = product_matrix(a, b, n);
    // print_matrix(a, n);
    // print_matrix(b, n);
    print_matrix(c, n);
    delete_matrix(a);
    delete_matrix(b);
    delete_matrix(c);
    return 0;
}
