#include <iostream>
using namespace std;

class Polynomial{
private:
   int coef[100]; 
   int deg;       
public:
    Polynomial::Polynomial(){
        for (int i = 0; i < 100; i++){
            coef[i] = 0;
        }
    }
    void set(int a, int b){
        coef[b] = a;
        deg = degree();
    }
    int degree(){
        int d = 0;
        for (int i = 0; i < 100; i++){
            if ( coef[i] != 0 ){ 
                d = i;
            }
        }
        return d;
    }
    void print(){
        for(int i = 99; i >= 0; i--){
            if(coef[i] != 0){
                cout << coef[i] << "x^" << i << " ";
            }
        }
    }
    int evaluate ( int x ){
        int p = 0;
        for(int i = deg; i >= 0; i--){
            p = coef[i] + ( x * p );
        }
        return p;
    }
    Polynomial differentiate(){
        if(deg == 0){
            Polynomial t;
            t.set (0, 0);
            return t;
        }
        Polynomial deriv;
        deriv.deg = deg - 1;
        for(int i = 0; i < deg; i++){
            deriv.coef[i] = (i + 1) * coef[i + 1];
        }
        return deriv;
    }
    Polynomial plus ( Polynomial b ){
        Polynomial a = *this;
        Polynomial c;
        for(int i = 0; i <= a.deg; i++){ 
            c.coef[i] += a.coef[i];
        }
        for(int i = 0; i <= b.deg; i++){ 
            c.coef[i] += b.coef[i];
        }
        c.deg = c.degree();
        return c;
    }
    Polynomial minus ( Polynomial b ){
        Polynomial a = *this; 
        Polynomial c;
        for(int i = 0; i <= a.deg; i++){ 
            c.coef[i] += a.coef[i];
        }
        for(int i = 0; i <= b.deg; i++){ 
            c.coef[i] -= b.coef[i];
        }
        c.deg = c.degree();
        return c;
    }
    Polynomial times ( Polynomial b ){
        Polynomial a = *this; 
        Polynomial c;
        for(int i = 0; i <= a.deg; i++){
            for(int j = 0; j <= b.deg; j++){
                c.coef[i+j] += (a.coef[i] * b.coef[j]);
            }
        }
        c.deg = c.degree();
        return c;
    }
};

int main(){
   Polynomial a, b, c, d;
   a.set (7, 4); 
   a.set (1, 2); 
   b.set (6, 3); 
   b.set (-3, 2); 
   c = a.minus (b); 
   c.print();
   cout << "\n";
   c = a.times (b); 
   c.print();
   cout << "\n";
   d = c.differentiate().differentiate();
   d.print();
   cout << "\n";
   cout << c.evaluate (2); 
   cin.get();
} 
