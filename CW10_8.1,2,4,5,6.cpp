#include <iostream>
#include <cstdio>
using namespace std;

const int N = 25;

// 08.01
void print(int a[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ends;
        cout << endl;
    }
    cout << endl;
}

// 08.04
void input(int a[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
}

void swap(int a[N][N], int i, int j, int ii, int jj) {
    int x = a[i][j];
    a[i][j] = a[ii][jj];
    a[ii][jj] = x;
}

// 08.02
void replace(int a[N][N], int i, int j, int b) {
    a[i][j] = b;
}

// 08.05
void transpose(int a[N][N], int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            int x = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = x;
        }
    }
}

// 08.06
int sum(int a[N][N], int n, int m, int k) {
    int s = 0;
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - j == k)
                s += a[i][j];
        }
    }
    cout << s << endl;
    */
    if (k > 0) {
        for (int i = 0; i < n && i < m; i++)
            s += a[i + k][i];
    }
    else {
        for (int i = 0; i < n && i < m; i++)
            s += a[i][i - k];
    }
    return s;
}

int main() {
    /*
    int a[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    print(a, 3, 3);
    swap(a, 1, 0, 2, 2);
    print(a, 3, 3);
    replace(a, 0, 0, 2);
    print(a, 3, 3);
    */

    int n, m;
    n = 3;
    m = 4;
    // cin >> n >> m;
    int b[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    // input(b, n, m);
    print(b, n, m);
    //transpose(b, n, m);
    //print(b, n, m);
    cout << sum(b, n, m, -1);
    return 0;
}
