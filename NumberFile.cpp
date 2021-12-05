#include <sstream>
#include "NumberFile.h"

#include "iostream"

const int MAX_LINES_COUNT=20;
const int MAX_NUMS_IN_LINE_COUNT=10;

void NumberFile::open(const std::string &filename, std::ios_base::openmode mode) {
    if (file.is_open()){
        close();
    }
    file.open(filename,mode);
    this->filename=filename;
    this->mode=mode;

    if (!file.good()){
        std::cout<<"Unable to open: "<<filename<<", mode: "<<mode<<std::endl;
        throw std::exception();
    }
}

void NumberFile::close() {
    if (!file.is_open()){
        std::cout<<"Unable to close file: "<<filename<<std::endl;
        throw std::exception();
    }
    file.close();
}

NumberFile::NumberFile(){

}

void NumberFile::inputLines() {
    try{
        file.close();
        file.open(filename,std::ofstream::out | std::ofstream::trunc);
        file.close();
        open(filename,mode);
    } catch (std::exception){
        std::cout<<"File was not cleared";
        throw std::exception();
    }

    std::vector<std::vector<double>> items;

    int count;
    std::cout<<"Input lines count: ";
    std::cin>>count;

    if (count>MAX_LINES_COUNT || count<=0){
        return;
    }

    for (int i=0; i<count; i++){
        int nums_count;
        std::cout<<"Input number of elements in line "<<i+1<<": ";
        std::cin >> nums_count;

        if (nums_count <= 0 || nums_count > MAX_NUMS_IN_LINE_COUNT){
            return;
        }

        std::vector<double> current_line;

        for (int j=0; j < nums_count; j++){
            double number;
            std::cout<<"Input number "<<j+1<<" of line "<<i+1<<": ";
            std::cin >> number;
            current_line.push_back(number);
        }

        items.push_back(current_line);
    }

    createFrom2DArray(items);
}

void NumberFile::createFrom2DArray(const std::vector<std::vector<double>>& items) {
    if (!file.is_open()){
        std::cout<<"File is not open, unable to write!"<<std::endl;
        throw std::exception();
    }

    try{
        file.close();
        file.open(filename,std::ofstream::out | std::ofstream::trunc);
        file.close();
        open(filename,mode);
    } catch (std::exception){
        std::cout<<"File was not overwritten";
        throw std::exception();
    }


    for (const std::vector<double>& line: items){
        for (double number: line){
            file<<number<<' ';
        }
        file<<std::endl;
    }
}

void NumberFile::printLines() {
    if (!file.is_open()){
        std::cout<<"File is not open, unable to read!"<<std::endl;
        throw std::exception();
    }
    file.seekg(0);
    std::string line;

    while (std::getline(file,line)){
        std::cout<<line<<std::endl;
    }
}

double NumberFile::getByIndex(int index) {

    std::vector<std::vector<double>> data = read();
    int _index = 0;

    for (const std::vector<double>& line: data){
        for (double number: line){
            if (_index==index){
                return number;
            }
            _index++;
        }
    }

    throw std::runtime_error("Element not found");
}

void NumberFile::appendLine(const std::vector<double>& line) {
    if (!file.is_open()){
        std::cout<<"File is not open, unable to write!"<<std::endl;
        throw std::exception();
    }
    close();
    open(filename,std::ios_base::out |std::ios_base::app);

    for (double number: line){
        file<<number<<' ';
    }
    close();
    open(filename,mode);

}

void NumberFile::removeByLineAndIndex(int line, int index) {
    if (!file.is_open()){
        std::cout<<"File is not open, unable to write!"<<std::endl;
        throw std::exception();
    }

    std::vector<std::vector<double>> data = read();

    std::vector<double> new_line;
    int d_index=-1;
    for (double d: data[line]){
        d_index++;
        if (d_index==index) continue;
        new_line.push_back(d);
    }

    data[line] = new_line;

    createFrom2DArray(data);
}

std::vector<std::vector<double>> NumberFile::read() {
    if (!file.is_open()){
        std::cout<<"File is not open, unable to read!"<<std::endl;
        throw std::exception();
    }
    file.seekg(0);

    std::string line_str;
    std::stringstream line_ss;

    std::vector<double> current_line;
    std::vector<std::vector<double>> lines;


    while (std::getline(file,line_str)){
        line_ss<<line_str;

        double number;
        while (line_ss>>number){
            current_line.push_back(number);
        }
        lines.push_back(current_line);

        current_line.clear();
        line_ss.clear();
    }


    return lines;
}
