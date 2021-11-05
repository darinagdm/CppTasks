#include <iostream>
#include <string>

std::string eraseEndOfWords(std::string line){
    int end_word = line.find(" ");
    line.replace(line.size()-1, 1, "");
    while(end_word != std::string::npos){
        line.replace(end_word-1, 1, "");
        end_word = line.find(" ", end_word);
    }
    return line;
}

void implaceEraseEndOfWords(std::string &line){
    int end_word = line.find(" ");
    line.replace(line.size()-1, 1, "");
    while(end_word != std::string::npos){
        line.replace(end_word-1, 1, "");
        end_word = line.find(" ", end_word);
    }
}

int main(){
    std::string str = "Today is a   good  day ";
    std::cout << str << std::endl << eraseEndOfWords(str);
}
