#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int n){
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int task_8_a(int list[], int n){
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (pow(floor(sqrt(list[i])), 2) == list[i]) {
            if (is_prime(sqrt(list[i]))) counter += 1;
        }
    }
    return counter;
}

int main() {
    int m[7] = {1, 2, 3, 4, 5, 6, 9};
    cout << "Result: " << task_8_a(m, 7) << endl;
}
