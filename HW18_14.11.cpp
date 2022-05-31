#include <iostream> 
#include <fstream> 
#include <string> 
 
using namespace std; 
 
void align(const char* filename) { 
    string arr[50]; 
    ifstream finp(filename); 
    if (!finp.good()) 
        exit(1); 
    int j=0; 
    while (finp.good()) { 
        string s; 
        getline(finp, s); 
        if (finp.fail()) 
            break; 
        int num_of_gaps;     
        if (s.length()%2!=0) { 
            num_of_gaps=(50-s.length()+1)/2; 
        } 
        else if (s.length()%2==0) { 
            num_of_gaps=(50-s.length())/2; 
        } 
        cout<<s.length()<<endl; 
        arr[j]=""; 
        int i=0; 
        while (i<num_of_gaps) { 
            arr[j]+=" "; 
            i++; 
        } 
        arr[j]+=s; 
        j++; 
    } 
    finp.close(); 
     
    ofstream fout(filename); 
    for (int i=0;i<j;i++) { 
        fout<<arr[i]<<endl; 
    } 
    fout.close(); 
} 
 
 
int main() { 
    align("input14.11.txt"); 
    return 0; 
}
