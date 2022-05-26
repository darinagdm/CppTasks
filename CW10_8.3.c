#include <stdio.h>
#define N 20
#define M 20

void ShowArray(double array[N][M], unsigned n, unsigned m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }
}

void InputArray(double array[N][M], unsigned n, unsigned m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }
}

int main() {
    int array[N][M];
    unsigned n = 21, m = 21;
    while (n > 20) {
        printf("n = ");
        scanf("%d", &n);
    }
    while (m > 20) {
        printf("m = ");
        scanf("%d", &m);
    }
    InputArray(array, n, m);
    ShowArray(array, n, m);
}
