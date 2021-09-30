#include <stdio.h> 
#include <math.h>

int main(){  //C 
  double x;
  scanf("%lf",&x); 
  x = log10(x);
  printf("\nResult = %.3lf", x);
}

/*
#include <iostream> //C++ 
#include <math.h>
using namespace std;
int main()
{
  double x;
  std::cin >> x;
  std::cout << "result = " << log10(x);
}
*\