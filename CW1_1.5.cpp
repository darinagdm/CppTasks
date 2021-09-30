#include <iostream> 
#include <string> 
 
int main() 
{ 
  double x,y; 
  scanf("%lf",&x); 
 
  //x4 za 2 
  y = x; 
  y = y*y; 
  y = y*y; 
  printf("%lf",y); 
  printf("%s", "\n"); 
  //x6 za 3 
  y = x; 
  y = y*y; 
  y = y*x; 
  y = y*y; 
  printf("%lf",y); 
  printf("%s", "\n"); 
  //x9 za 4 
  y = x; 
  y = y*y; 
  y = y*y; 
  y = y*y; 
  y = y*x; 
  printf("%lf",y); 
  printf("%s", "\n"); 
  //x15 za 5 
  y = x; 
  y = y*y; 
  y = y*y; 
  y = y*x; 
  y = y*y*y; 
  printf("%lf",y); 
  printf("%s", "\n"); 
  //x28 za 6 
  y = x; 
  y = y*y; 
  y = y*x; 
  y = y*y; 
  y = y*x; 
  y = y*y; 
  y = y*y; 
  printf("%lf",y); 
  printf("%s", "\n"); 
 
  //x64 za 6 
  y = x; 
  y = y*y; 
  y = y*y; 
  y = y*y; 
  y = y*y; 
  y = y*y; 
  y = y*y; 
  printf("%lf",y); 
  printf("%s", "\n"); 
}
