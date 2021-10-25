#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  char response = 'y';
  while (response != 'n') {
    int length, sum = 0;
    cin >> length;
    int *array = new int[length];
    int z; 
    for(int i = 0; i < length; i++) {
      cin >> array[i];
    }
    for (int i = 0; i < length; i++) {
      sum += array[i];
    }
    float arithmetic_mean = float(sum)/length;
    for (int col = 0; col < length; col++) {
        cout << array[col] << " " << ends;
    }
    cout << "\n";
    cout << "\nArithmetic mean: " << arithmetic_mean << endl;
    cout << "Despersion: " << ends;
    for (int i = 0; i < length; i++) {
      printf("%.2f ", abs(array[i] - float(arithmetic_mean)));
    }
    cout << "Continue? (y/n) " << endl;
    cin >> response;
  }
}
