#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    char fname[20] = "deutsch.txt";
    ifstream f(fname);
    string Artikles[] = {"der", "das", "die"};
    string buf;
    bool art = false;
    
    ofstream f2("tmp.txt");
    while(f>>buf){
        if(art){
            buf[0] = toupper(buf[0]);
        }
        clog<<buf<<" ";
        f2<<buf<<" ";
        art = false;
        for(int i=0;i<6;i++){
            if(buf==Artikles[i]){
                art = true;
                break;
            }
        }
    }
    f.close();
    f2.close();
    rename("tmp.txt", fname);
}
