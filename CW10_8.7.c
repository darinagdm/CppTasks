#include <stdio.h>
#include <math.h>
#define N 100
#define M 100

void printArray(double array[N][M], unsigned n, unsigned m) {
    printf("\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%g ", array[i][j]);
        }
        printf("\n");
    }
}

void inputArray(double array[N][M], unsigned n, unsigned m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }
}

void columnSwap(double array[N][M], unsigned n, unsigned m, unsigned col1, unsigned col2) {
    double swapper[N];
    for (unsigned i=0; i<n; i++) {
        swapper[i] = array[i][col1];
    }
    for (unsigned i=0; i<n; i++) {
        array[i][col1] = array[i][col2];
        array[i][col2] = swapper[i];
    }
}

void DiagMaxElAlining(double array[N][M], unsigned n, unsigned m) {
    double max_el;
    int col;
    for (unsigned i=0; i<n; i++) {
        max_el = 0;
        for (unsigned j=0; j<m; j++) {
            if (array[i][j] > max_el) {
                max_el = array[i][j];
                col = j;
            }
            columnSwap(array, n, m, i, j);
        }
    }
}

int main() {
    unsigned n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    double array[N][M];
    inputArray(array, n, m);
    printArray(array, n, m);
    DiagMaxElAlining(array, n, m);
    printArray(array, n, m);
}
