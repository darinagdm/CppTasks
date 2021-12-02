#include <ostream>
#include "Point2D.h"
#include "Line2D.h"

#ifndef HOMEWORK15_TRIANGLE_H
#define HOMEWORK15_TRIANGLE_H

using std::cout;
using std::cin;
using std::endl;

class Triangle {
private:
    Point2D A,B,C;
    Line2D AB,BC,AC;
public:
    Triangle(Point2D A, Point2D B, Point2D C){
        this->A=A;
        this->B=B;
        this->C=C;
        AB = Line2D(A,B);
        BC = Line2D(B,C);
        AC = Line2D(A,C);
    }

    Triangle(){

    }

    void input(){
        cout<<"Input point 1 of triangle:"<<endl;
        A.input();
        cout<<"Input point 2 of triangle:"<<endl;
        B.input();
        cout<<"Input point 3 of triangle:"<<endl;
        C.input();
        AB = Line2D(A,B);
        BC = Line2D(B,C);
        AC = Line2D(A,C);
    }

    double perimeter(){
        return AB.length()+BC.length()+AC.length();
    }

    double square(){
        double p = perimeter()/2;
        return sqrt(p*
            (p-AB.length())*
            (p-BC.length())*
            (p-AC.length()));
    }

    const Point2D &getA() const {
        return A;
    }

    const Point2D &getB() const {
        return B;
    }

    const Point2D &getC() const {
        return C;
    }

    friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
        os << "Triangle( A: " << triangle.A << " B: " << triangle.B << " C: " << triangle.C << " )";
        return os;
    }
};


#endif //HOMEWORK15_TRIANGLE_H
