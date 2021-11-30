#ifndef Rational_h
#define Rational_h
#include <iostream>
#include <cmath>
#include <exception>

class Rational{
    private:
    int nom;
    unsigned denom;
    public:
    Rational(){
        nom = 1;
        denom = 1U;
    }
    Rational(int x, unsigned y):nom(x),denom(y){
        reduce();
    }
    void show();
    int input();
    int setNom(int x){
        nom = x;
        return 0;
    }
    int setDenom(unsigned y){
        if(y!=0){
            denom = y;
            return 0;
        }
        return -1;
    }

    Rational add(const Rational& x); 
    Rational mult(const Rational& x);
    Rational operator+(const Rational& x){
        return add(x);
    }
    Rational operator*(const Rational& x){
        return mult(x);
    }
    Rational operator-(const Rational& x){
        int ch= static_cast<int>(x.denom*nom-x.nom*denom);
        unsigned zn=x.denom*denom;
        return Rational(ch,zn);
    }
    Rational operator/(const Rational& x){
        int ch= static_cast<int>(x.denom*nom);
        unsigned zn=x.denom*nom;
        return Rational(ch,zn);
    }
    Rational operator-(){
        return Rational(-nom,denom);
    }
    bool less(const Rational & x){
        return (nom*x.denom<denom*x.nom);
    }
    double compare(double z){
        return fabs(z - (nom+0.)/denom);
    }
    bool operator<(const Rational & x){
        return less(x);
    }
    bool operator==(const Rational & x){
        return (nom*x.denom==denom*x.nom);
    }
    bool operator!=(const Rational & x){
        return (nom*x.denom!=denom*x.nom);
    }
    bool operator<(const double x){
        return fabs(x-static_cast<double>(nom)/denom);
    }
    static unsigned gcd(unsigned x, unsigned y);
    private:
    void reduce();
};

#endif 
