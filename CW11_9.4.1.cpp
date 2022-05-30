#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int** create_matrix(int n) {
    int** a = (int**) malloc(n * sizeof *a);
    if (a == nullptr)
        exit(1);
    for (int i = 0; i < n; i++) {
        a[i] = (int*) calloc(n, sizeof **a);
        if (a[i] == nullptr)
            exit(1);
    }
    return a;
}

void delete_matrix(int** a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

int** input_matrix(int n) {
    int** a = create_matrix(n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    return a;
}

void print_matrix(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ends;
        }
        cout << endl;
    }
    cout << endl;
}

int** product_matrix(int** a, int** b, int n) {
    int** c = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    int** a = input_matrix(n);
    int** b = input_matrix(n);
    int** c = product_matrix(a, b, n);
    print_matrix(a, n);
    print_matrix(b, n);
    print_matrix(c, n);
    delete_matrix(a, n);
    delete_matrix(b, n);
    delete_matrix(c, n);
    return 0;
}
