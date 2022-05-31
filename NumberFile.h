#ifndef HOMEWORK17_NUMBERFILE_H
#define HOMEWORK17_NUMBERFILE_H

#include <fstream>
#include "iostream"
#include "vector"
using std::ifstream;
using std::ofstream;

class NumberFile {
private:
    std::string filename;
    std::ios_base::openmode mode;
    unsigned int numbers_count;
    unsigned int lines_count;
    std::fstream file;
public:
    NumberFile();
    void inputLines();
    void createFrom2DArray(const std::vector<std::vector<double>>& items);
    void printLines();
    double getByIndex(int index);
    void appendLine(const std::vector<double>& line);
    void removeByLineAndIndex(int line, int index);
    std::vector<std::vector<double>> read();
    void open(const std::string &filename,std::ios_base::openmode mode);
    void close();
};


#endif //HOMEWORK17_NUMBERFILE_H
