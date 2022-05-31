#include <iostream>
#include <fstream>
using namespace std;

int getDoubles(const char* fname, char delim, double* mas, int n){
    double x;
    int k=0;
    char d;
    std::string s;
    std::ifstream f1(fname);
    
    if(f1.bad()){
        std::cerr<<"Error opening file"<<fname<<std::endl;
    }
    while(!f1.eof() && k<n){
        if(f1>>x){
            mas[k++] = x;
        }
        else{break;}
        if(f1>>d){
            if(d==delim)continue;
            else{
                std::cerr<<"Error in file";
            }
        }
        else{break;}
        k++;
    }
    f1.close();
    return k;
}

int main(){
    std::string fname;
    std::cout<<"Input filename: ";
    std::cin>>fname;
    std::cout<<"Input n and delimeter: ";
    int n;
    std::cin>>n;
    char delim;
    std::cin>>delim;
    double* mas = new double[n];
    
    int k = getDoubles(fname.c_str(), delim, mas, n);
    for(int i=0;i<n;i++){
        std::cout<<mas[i]<<", ";
    }
    delete[] mas;
}

