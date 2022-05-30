#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

const char* fin_name = "inp.txt";
const char* fout_name = "out.txt";

int main() {
    unsigned n;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        cout << i+1 << ": ";
        cin >> arr[i];
    }
    
    ifstream fin;
    fin.open(fin_name);
    if(!fin){
        cout << "Couldn`t open file";
        return -1;
    }
    
    double* x = (double*)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++){
        if(fin.eof()){
            cout << "Not enough elements in file";
            return -2;
        }
        
        fin >> x[i];
    }
    fin.close();
    ofstream fout;
    fout.open(fout_name);
    for(int i=0;i<n;i++){
        fout << pow(x[i], arr[i]) << endl;
    }
    fout.close();
    free(x);
    free(arr);
}
