#include <stdio.h>
#include <math.h>
 

void shortest_distance(float x1,float y1,float a,float b,float c){
    float d = fabs((a*x1 + b*y1 + c))/(sqrt(a*a + b*b));
    printf("Перпендикулярна відстань %f\n", d);
    return;
}

int main(){
    float x1 = 2;
    float y1 = 3;
    float a = -2;
    float b = 5;
    float c = 4;
    shortest_distance(x1, y1, a, b, c);
    return 0;
}
