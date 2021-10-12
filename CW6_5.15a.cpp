#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int fac(int N)
{
    int F = 1; 
    for(int i=1; i<=N; ++i){
        F *= i; 
    }
    return F;
}
 
double mb( double x, int n ){
   return pow(-1,n) * pow( x, 2*n+1 ) / fac(2*n+1);
}
 
int main(){
   double e;
   double x;
   printf( "Input X:\n");
   scanf( "%lf", &x );
   printf( "Input e:\n");
   scanf( "%lf", &e );
   
   double sinus = 0;
   int n=0;
   double m;
   
   do
   {
      m = mb(x, n++ );
      sinus += m;
   }
   while(fabs(m) > e);
   
   printf( "sin(%lf)=%lf\n", x, sinus );
 
   return 0;
}
