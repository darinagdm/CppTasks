#include<iostream> 
#include<iomanip> 
#include<cmath> 
#include<fstream> 
using namespace std; 
 
int main(){ 
    double inp[1000]; 
    ifstream finp; 
    finp.open("input.txt"); 
    int i=0; 
    while(!finp.eof()){ 
        finp>>inp[i]; 
        finp.ignore(256,';'); 
        if (finp.fail()) 
            break; 
        i++; 
 
    } 
    finp.close(); 
 
    for (int l=0;l<i;l++) 
        cout<<inp[l]<<ends; 
 
    cout<<endl; 
 
    ofstream fout; 
    fout.open("out_12.7.txt"); 
    double out[1000]; 
    int k=0; 
    for (int j=0;j<i;j++){ 
        if (abs(inp[j])<=1){ 
            fout<<scientific<<asin(inp[j])<<ends; 
            out[k]=asin(inp[j]); 
            k++; 
        } 
    } 
    fout.close(); 
 
    for (int p=0;p<k;p++) 
        cout<<scientific<<out[p]<<ends; 
 
}
