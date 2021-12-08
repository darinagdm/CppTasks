#include <iostream>
#include "src/main/Matrix.h"

void task19_12(){
    std::vector<std::vector<int>> mat = {{1,2,4},{3,4,5}};
    Matrix<int> m(mat);

    std::vector<std::vector<int>> mat2 = {{-1,0,4},{-4,2,8}};
    Matrix<int> m2(mat2) ;

    m.transpose();
    Matrix<int> mul = m*m2;

    std::cout<<"even numbers: M1 = "<<m<<"\nM2 = "<<m2<<"M1*M2 = "<<mul<<std::endl;

    std::vector<std::vector<float>> mat3 = {{1.3,2.0,-4.6},{0.1,0.2,-0.4}};
    Matrix<float> m3(mat3);

    std::vector<std::vector<float>> mat4 = {{-1.5,10.88,4.5},{-4.14,2.71,8.89}};
    Matrix<float> m4(mat4);

    m3.transpose();

    Matrix<float> mul2 = m4*m3;

    std::cout<<"floating-point: \n M1 = "<<m4<<"\nM2 = "<<m3<<"M1*M2 = "<<mul2<<std::endl;
}

int main() {
    std::cout<<"Task 19.12"<<std::endl;
    task19_12();
    std::cout<<"\n\n\n\n";
    return 0;
}
