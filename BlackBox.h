#ifndef HOMEWORK18_BLACKBOX_H
#define HOMEWORK18_BLACKBOX_H
#include "vector"
#include "iostream"
#include "BlackBox.h"
#include "random"

const int MAX_ITEMS_COUNT = 100;

template <typename T>
class BlackBox {
private:
    std::vector<T> array;

    std::random_device rd;
    std::mt19937 mt = std::mt19937(rd());

    int random_in_range(int min, int max){

        std::uniform_int_distribution<int> r(min,max);
        return r(mt);
    }

public:
    BlackBox() = default;
    BlackBox(std::vector<T> &array){
        if (array.size()>MAX_ITEMS_COUNT) {
            std::cout<<"array size > "<<MAX_ITEMS_COUNT<<std::endl;
            throw std::exception();
        }
        this->array=array;
    }
    void push(T element){
        array.push_back(element);
    }
    T pop(){
        int index = random_in_range(0,array.size()-1);
        T item = array.at(index);
        array.erase(array.begin()+index);
        return item;
    }
    T xpop(){
        int index = random_in_range(0,array.size()-1);
        return array.at(index);
    }

};

#endif //HOMEWORK18_BLACKBOX_H
