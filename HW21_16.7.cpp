#include <iostream>
#include <cmath>
#define N 100
using namespace std;

class Shape {

public:

    double side(double x1, double y1, double x2, double y2) {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }

    virtual void print(ostream& out = cout, bool endline = true) = 0;
    virtual double getRight() = 0;
    virtual double getLeft() = 0;
    virtual double perimeter() = 0;
    virtual double square() = 0;
    virtual void moving(double x, double y) = 0;
};


class Trapezoid: public Shape {

private:

    double x1, x2, x3, x4;
    double y1, y2, y3, y4;

public:

    Trapezoid(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4):
            x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4) {}

    double getRight() override {
        return max(x1, max(x2, max(x3, x4)));
    }

    double getLeft() override {
        return min(x1, min(x2, min(x3, x4)));
    }


    void input(istream& inp = cin) {
        inp >>x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }


    void print(ostream& out = cout, bool endline = true) override{
        out << '(' << x1 << ' ' << y1 << ')' << '(' << x2 << ' ' << y2 << ')' << '(' << x3 << ' ' << y3 << ')' << '(' << x4 << ' ' << y4 << ')';
        if (endline) out << endl;
    }


    double perimeter() {
        double a = side(x1, y1, x2, y2);
        double b = side(x2, y2, x3, y3);
        double c = side(x3, y3, x4, y4);
        double d = side(x4, y4, x1, y1);
        return (a + b + c + d);
    }

    double square() {
        return (side(x2, y2, x3, y3) + side(x4, y4, x1, y1))/2 * (y3 - y4);
    }


    void moving(double x, double y) {
        double x_delta = x - getLeft();
        double y_delta = y - y1;
        this->x1 = x1 + x_delta;
        this->y1 = y1 + y_delta;
        this->x2 = x2 + x_delta;
        this->y2 = y2 + y_delta;
        this->x3 = x3 + x_delta;
        this->y3 = y3 + y_delta;
        this->x4 = x4 + x_delta;
        this->y4 = y4 + y_delta;
    }

};


class Parallelogram: public Shape {

private:

    double x1, x2, x3, x4;
    double y1, y2, y3, y4;

public:

    Parallelogram(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4):
            x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4) {}


    double getRight() override {
        return max(x1, max(x2, max(x3, x4)));
    }

    double getLeft() override {
        return min(x1, min(x2, min(x3, x4)));
    }



    void input(istream& inp = cin) {
        inp >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }

    void print(ostream& out = cout, bool endline = true) override{
        out << '(' << x1 << ' ' << y1 << ')' << '(' << x2 << ' ' << y2 << ')' << '(' << x3 << ' ' << y3 << ')' << '(' << x4 << ' ' << y4 << ')';
        if (endline) out << endl;
    }


    double perimeter() {
        double a = side(x1, y1, x2, y2);
        double b = side(x2, y2, x3, y3);
        return 2 * (a + b);
    }

    double square() {
        return side(x1, y1, x4, y4) * (y3 - y1);
    }

    void moving(double x, double y) {
        double x_delta = x - getLeft();
        double y_delta = y - y1;
        this->x1 = x1 + x_delta;
        this->y1 = y1 + y_delta;
        this->x2 = x2 + x_delta;
        this->y2 = y2 + y_delta;
        this->x3 = x3 + x_delta;
        this->y3 = y3 + y_delta;
        this->x4 = x4 + x_delta;
        this->y4 = y4 + y_delta;
    }


};


class Circle: public Shape {

private:

    double x, y, r;

public:

    Circle(double _x, double _y, double _r):
            x(_x), y(_y), r(_r) {}


    double getRight() {
        return x + r;
    }

    double getLeft() {
        return x - r;
    }



    void input(istream& inp = cin) {
        inp >> x >> y >> r;
    }

    void print(ostream& out = cout, bool endline = true) override{
        out << '(' << x << ' ' << y << ')' <<  ' ' << r;
        if (endline) out << endl;
    }


    double pi(double eps = 0.0001) {
        double s = 1.0;
        double a = 1.0;
        int i = 1;
        while (abs(a) > eps) {
            i++;
            a = (i % 2 ? 1.0 : -1.0) / i / i;
            s += a;
        }
        return sqrt(s * 12.0);
    }


    double square() {
        return pi() * r * r;
    }


    double perimeter() {
        return 2 * pi() * r;
    }


    void moving(double x, double y) {
        this->x = x + r;
        this->y = y;
    }



};



int main() {

    //Parallelogram p(0,0,2,2,6,2,4,0);
    //Trapezoid t(2, 1, 3, 3, 5, 3, 8, 1);
    //Circle c(0, 0, 5);

    int n = 4;
    Shape* arr[N] = {
            new Parallelogram(2,2,4,5,12,5,10,2),
            new Trapezoid(9, 4, 9, 7, 12, 7, 16, 4),
            new Circle(4, 6, 2),
            new Circle(12, 7, 1)
    };

    double perimeter_all = arr[0]->perimeter(), square_all = arr[0]->square(), max_square = arr[0]->square();
    double tmp_sq;
    double x = arr[0]->getRight();
    double y = 0;
    for (int i = 1; i < n; i++) {
        arr[i]->moving(x + 1, y);
        x = arr[i]->getRight();
        arr[i]->print();
        cout << "Left x: " << arr[i]->getLeft() << endl;
        cout << "Right x: " << arr[i]->getRight() << endl;
        cout << endl;
        perimeter_all += arr[i]->perimeter();
        tmp_sq = arr[i]->square();
        square_all += tmp_sq;
        if (tmp_sq > max_square)
            max_square = tmp_sq;
    }

    for (int i = 0; i < n; i++)
        delete arr[i];


    cout << "Total perimeter " << perimeter_all << endl;
    cout << "Total square " << square_all << endl;
    cout << "Max square " << max_square << endl;

    return 0;
}
