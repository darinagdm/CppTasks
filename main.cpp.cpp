#include <iostream>
#include "src/main/NumberFile.h"

void openFile(NumberFile &numberFile, const std::string &filename){
    try {
        numberFile.open(filename,std::fstream::in | std::fstream::out);
    } catch(std::exception){
        numberFile.open(filename,std::fstream::in | std::fstream::out | std::fstream::trunc);
    }
}

void task17_07(){
    NumberFile numberFile;

    std::cout<<"1) Input line by line:"<<std::endl;
    try{
    openFile(numberFile,"file.txt");
    numberFile.inputLines();
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 1";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    std::cout<<"2) Print lines:"<<std::endl;
    try {
        openFile(numberFile,"file.txt");
        numberFile.printLines();
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 2";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    std::cout<<"3) Remove number with index 1 in line with index 1:"<<std::endl;
    try {
    openFile(numberFile,"file.txt");
    numberFile.removeByLineAndIndex(1,1);
    numberFile.printLines();
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 3";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    std::cout<<"4) Get element with index 5:"<<std::endl;
    try {
    openFile(numberFile,"file.txt");
    std::cout<<"Element with index 4: "<<numberFile.getByIndex(5);
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 4";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    std::cout<<"5) Append line to file"<<std::endl;
    try {
        std::vector<double> vector = {2.2,34.2,-7.5};
        openFile(numberFile,"file.txt");
        numberFile.appendLine(vector);
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 5";
    }

    std::cout<<"File contents after append:"<<std::endl;
    try {
        openFile(numberFile,"file.txt");
        numberFile.removeByLineAndIndex(1,1);
        numberFile.printLines();
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 6";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

}

int main() {
    task17_07();
    return 0;
}
