#ifndef Poly_h
#define Poly_h
#include <cstddef>

using namespace std;

typedef double PTYPE;

class Poly{
    size_t n;
    PTYPE *a;
    public:
    Poly(){
        n=0;
        a=NULL;
    }
    Poly(size_t n);
    Poly(size_t n_, PTYPE* arr);
    Poly(const Poly& p){
        n=p.n;
        a=new PTYPE[n+1];
        for(int i=0; i<n+1;++i){
            a[i]=p.a[i];
        }
    }
    ~Poly(){
        delete[] a;
    }
    
    Poly operator=(const Poly &p){
            n=p.n;
            if(a)delete[] a;
            a=new PTYPE[n+1];
            for(int i=0;i<n+1;++i){
                a[i]=p.a[i];
            }
            return *this;
        }
        
    void setPoly(size_t n_, PTYPE * arr);
    void setCoef(size_t k, PTYPE a);
    void show();
    PTYPE value(PTYPE x);
    friend int inputFromFile(const char* fname, Poly& p);
    friend int outputFromFile(const char* fname,const Poly& p);
};

#endif 
