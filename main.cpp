#include <iostream>
#include "vector"
#include "src/main/BlackBox.h"
void task18_03(){
    std::vector<int> ints = {1,2,32,3,4};
    BlackBox<int> blackBox(ints);
    blackBox.push(38);

    for (int i=0; i<ints.size(); i++){ //Expected: out of range
        std::cout<<blackBox.pop()<<' '<<blackBox.xpop()<<std::endl;
    }
}

int main() {
    //Task 18.03
    task18_03();
    return 0;
}
