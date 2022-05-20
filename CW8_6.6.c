#include <stdio.h>
#include <limits.h>

//returns max divisor of x in form 2^k
unsigned f1(unsigned x){
   unsigned k=0;
   unsigned p=1;
   if(x==0) return 0;
   while(p<=x){
       if(x%p==0){k++; p<<=1;}
       else break;
   }
   return p/2;
} 

//returns 0 if x=2^k, 1 - in another cases
unsigned f2(unsigned x){
   unsigned k=0;
   unsigned p=1;
   while(p<=x){
       if(x%p==0){k++; p<<=1;}
       else break;
   }
   return (p/2==x)?1:0;
} 

int main(){
    unsigned x;
    for(x=0;x<UINT_MAX/2;++x){
        unsigned y = x & (x-1);
        unsigned z = x & (-x);
        //printf("%u %u\n",z,f1(x));
        //printf("z=%u %u\n",(y==0)?1:0,f2(x));
        if(z!=f1(x)){
            printf("Fail for x=%x x& -x =%u, f1=%u\n",x,z,f1(x));
        }
        if(y!=f2(x)){
            printf("Fail for x=%x x& (x-1) =%u, f1=%u\n",x,(y==0)?1:0,f2(x));
        }
        //printf("x=%x y=%y z=%x \n",x,y,z);
    }
}
