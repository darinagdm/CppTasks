#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int input(int** a) {
    *a = (int*) malloc(0 * sizeof **a);
    int n = 0;
    if (*a) {
        while (n < 20) {
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

/*void print(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ends;
    cout << endl;
}*/

float harmonicMean(int arr[], int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (float)1 / arr[i];
    return (float)n/sum;
}

float geometricMean(int arr[], int n)
{
    float product = 1;
    for (int i = 0; i < n; i++)
        product = product * arr[i];
    float gm = pow(product, (float)1 / n);
    return gm;
}

int main() {
    int* a;
    int n = input(&a);
    //print(a, n);
    cout << harmonicMean(a,n) << endl;
    cout << geometricMean(a,n)<< endl;
    free(a);
    return 0;
}
