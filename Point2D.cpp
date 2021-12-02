#include "Point2D.h"

Point2D::Point2D(){
    this->x=-DBL_MAX;
    this->y=-DBL_MAX;
}

Point2D::Point2D(double x, double y) {
    this->x=x;
    this->y=y;
}

std::ostream &operator<<(std::ostream &os, const Point2D &d) {
    os << "Point2D( x=" << d.x << ", y=" << d.y<<" )";
    return os;
}

bool Point2D::operator==(const Point2D &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point2D::operator!=(const Point2D &rhs) const {
    return !(rhs == *this);
}
