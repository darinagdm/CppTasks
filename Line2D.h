#include <ostream>
#include <cmath>
#include "Point2D.h"

#ifndef HOMEWORK15_LINE2D_H
#define HOMEWORK15_LINE2D_H

class Line2D {
private:
    Point2D a;
    Point2D b;

public:
    Line2D(Point2D &a, Point2D &b){
        this->a=a;
        this->b=b;
    }

    Line2D() {

    }

    Point2D getCenter(){
        return Point2D(a.getX()/2+b.getX()/2,
                       a.getY()/2+b.getY()/2);
    }

    double length(){
        return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));
    }

    Point2D intersection(Line2D other) {
        if (*this==other){
            return a;
        }

        Point2D C,D;
        C = other.getA();
        D = other.getB();

        double a1 = b.getY() - a.getY();
        double b1 = a.getX() - b.getX();
        double c1 = a1 * (a.getX()) + b1 * (a.getY());

        double a2 = D.getY() - C.getY();
        double b2 = C.getX() - D.getX();
        double c2 = a2 * (C.getX()) + b2 * (C.getY());

        double determinant = a1 * b2 - a2 * b1;

        if ((long)(determinant*1000) == 0L) {
            return Point2D(-DBL_MAX, -DBL_MAX);
        } else {
            double x = (b2 * c1 - b1 * c2) / determinant;
            double y = (a1 * c2 - a2 * c1) / determinant;
            Point2D point(x, y);

            if (!containsPoint(point) ||
                !other.containsPoint(point)){
                return Point2D(-DBL_MAX, -DBL_MAX);
            }

            return point;
        }
    }

    bool containsPoint(Point2D point){
        long v_1_x = (long)((a.getX()-b.getX())*10000);
        long v_1_y = (long)((a.getY()-b.getY())*10000);
        long v_2_x = (long)((a.getX()-point.getX())*10000);
        long v_2_y = (long)((a.getY()-point.getY())*10000);

        long v1 = (long)((double)v_1_x/v_2_x),
             v2 = (long)((double)v_1_y/v_2_y);

        return (v1 == v2 & v1>0 & v2>0);
    }

    bool operator==(const Line2D &rhs) const {
        return a == rhs.a &&
               b == rhs.b;
    }

    bool operator!=(const Line2D &rhs) const {
        return !(rhs == *this);
    }


    const Point2D &getA() const {
        return a;
    }

    void setA(const Point2D &A) {
        Line2D::a = A;
    }

    const Point2D &getB() const {
        return b;
    }

    void setB(const Point2D &B) {
        Line2D::b = B;
    }

    friend std::ostream &operator<<(std::ostream &os, const Line2D &d) {
        os << "Line2D( " << d.a << "," << d.b << " )";
        return os;
    }
};


#endif //HOMEWORK15_LINE2D_H
