#include <iostream>
#include <cmath>

using namespace std;

float func(float eps){
    float a, num, b;
    a = sqrt(2)/2;
    num = sqrt(2);
    b = a;
     
  while((sqrt(2 + num)/2) > eps){
    b *= (sqrt(2 + num)/2);
    num = sqrt(2 + num);
  }  
  return b;
}

int main(){
    float eps;
    cout << "eps=" ;
    cin >> eps;
    cout << "Approximation of 2/pi: " << func(eps) << endl;
    return 0;
}
