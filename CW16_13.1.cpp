#include <iostream>
#include <string>
using namespace std;

std::string newStrAfterDoubleDot(std::string line){
    int start = line.find(":") + 1;
    int endline = line.find(",", start);
    std::string res = line.substr(start, endline-start);
    return res;
}

void changeStrAfterDoubleDot(std::string &line){
    int start = line.find(":") + 1;
    int endline = line.find(",", start);
    line = line.substr(start, endline-start);
}

int main(){
    std::string str = "weather: sunny, cloudy";
    std::cout << newStrAfterDoubleDot(str) << std::endl;
    changeStrAfterDoubleDot(str);
    std::cout << str;
}
