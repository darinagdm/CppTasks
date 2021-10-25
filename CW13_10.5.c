#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80

typedef struct {
    char title[N];
    int height;
} Peak;

void print(Peak a) {
    printf("Mountain: %s, height: %ld\n", a.title, a.height);
}

void print_array(Peak arr[], int n) {
    for (int i = 0; i < n; i++)
        print(arr[i]);
}

Peak input() {
    Peak a;
    scanf("%79s %ld", a.title, &a.height);
    return a;
}

void highest_peak(Peak arr[], int n, char* result) {
    int m = 0;
    int max_height = arr[0].height;
    for (int i = 1; i < n; i++) {
        if (arr[i].height > max_height) {
            max_height = arr[i].height;
            m = i;
        }
    }
    strcpy(result, arr[m].title);
}

int peak_height(Peak arr[], int n, char* title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].title, title) == 0)
            return arr[i].height;
    }
    return -1;
}

int main() {
    int n = 4;
    Peak p[N] = {
        {"Hoverla", 2600},
        {"Everest", 8000},
        {"Elbrus", 4000}
    };
    p[n - 1] = input();
    print_array(p, n);
    char highest_peak_title[N];
    highest_peak(p, n, highest_peak_title);
    printf("\nHighest peak: %s\n", highest_peak_title);
    char title[N];
    scanf("%79s", title);
    int height = peak_height(p, n, title);
    printf("\nHeight of %s: %ld\n", title, height);
    return 0;
}
