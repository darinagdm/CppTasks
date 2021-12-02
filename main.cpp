#include <iostream>
#include "src/Point2D.h"
#include "src/Line2D.h"
#include "src/Triangle.h"

using std::endl;
using std::cout;
using std::cin;

int main() {
    Point2D a(0,0),
            b(1,2),
            c(0,-1),
            d(1,0);
    //std::cout<<"Input points (4):";
    /*
    a.input();
    b.input();
    c.input();
    d.input();
    */

    Line2D line1(a,b);
    Line2D line2(c,d);
    cout<<"Line1: "<<line1<<endl<<
          "Line2: "<<line2<<endl;
    cout<<"Line intersection"<<line1.intersection(line2)<<endl;

    cout<<"Input Triangle: "<<endl;
    Triangle triangle;
    triangle.input();

    cout<<triangle<<endl
        <<triangle.perimeter()<<endl
        <<triangle.square()<<endl;

    return 0;
}
