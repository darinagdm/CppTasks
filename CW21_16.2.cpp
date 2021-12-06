#include <iostream>
#include <cmath>

class Point{
    int d;
    
public:
    void setd(int d){
        this->d = d;
    }
    int getd(){
        return d; 
    }
};

class Point2D: public Point{
    int x, y;
    
public:
    Point2D(){}
    Point2D(int x1, int y1): x(x1), y(y1){}

    virtual void input(){
        std::cout << "p(x,y) = ";
        std::cin >> x >> y;
    }

    virtual void show(){
        std::cout << "p(" << x << ", " << y <<")\n";
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};

class Point3D: public Point2D{
    int z;

public:
    Point3D(){}
    Point3D(int x1, int y1, int z1):Point2D(x1,y1), z(z1){}

    void input(){
        std::cout << "p(x,y,z)=";
        std::cin >> x >> y >> z;
    }

    void show(){
        std::cout << "p(" << x << ", " << y << ", " << z <<")\n";
    }

    int getZ(){
        return z;
    }
};

class Vector{
    Point2D *p1;
    Point2D *p2;
    
public:
    void input(){
        int n;
        std::cin >> n;
        
        if(n == 2){
            p1->input();
            p2->input();
        }
        
        if (n == 3){
            Point3D q1,q2;
            q1.input();
            q2.input();
            p1=dynamic_cast<Point2D>(&q1);
            p2=dynamic_cast<Point2D>(&q2);
        }
    }

    void show(){
        p1.show();
        p2.show();
    }

    double length(){
        if(getDim() == 2){
            int x1 = p1.getX();
            int y1 = p1.getY();
            int x2 = p2.getX();
            int y2 = p2.getY();
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
        
        else{
            int x1 = p1.getX();
            int y1 = p1.getY();
            int z1 = p1.getZ();
            int x2 = p2.getX();
            int y2 = p2.getY();
            int z2 = p2.getZ();
            
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+-(z1-z2)*(z1-z2));
        }
    }
}

int main() {
    return 0;
}
