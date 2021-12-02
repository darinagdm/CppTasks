#include <iostream>

#ifndef HOMEWORK15_POINT2D_H
#define HOMEWORK15_POINT2D_H

const double DBL_MAX = 1.79e308;

class Point2D {
private:
    double x;
    double y;

public:
    Point2D(double x, double y);

    Point2D();

    Point2D input(){
        std::cout<<std::endl<<"Input X coordinate of a point: ";
        std::cin>> this->x;

        std::cout<<std::endl<<"Input Y coordinate of a point: ";
        std::cin>> this->y;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point2D &d);

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setX(double X) {
        this->x = X;
    }

    void setY(double Y) {
        this->y = Y;
    }

    bool operator==(const Point2D &rhs) const;

    bool operator!=(const Point2D &rhs) const;
};


#endif //HOMEWORK15_POINT2D_H
