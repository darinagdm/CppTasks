#include <iostream>                
#include <string>                
#include <math.h>               

using namespace std;                
int main(int argc, char* argv[])                
{                
    double x1,x2,y1,y2,distance;              

        cout <<"Введіть координату x1:"<<endl;             
        cin>>x1;                     
        cout <<"Введіть координату y1:"<<endl;             
        cin>>y1;             
        cout <<"Введіть координату x2:"<<endl;             
        cin>>x2;             
        cout <<"Введіть координату y2:"<<endl;             
        cin>>y2;                              distance=sqrt(pow((x2-x1),2)+pow((y2-y1),2));      // формула для вычисления расстояния 
 cout<<"Відстань між двома точками:"<<distance<<endl;                
}