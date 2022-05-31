#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(){
    const char fname[] = "1.txt";
    fstream f(fname);
    string word;
    map<string,int> ch;
    int total = 0;
    while(f>>word){
        cout<<word<<",";
        total++;
        if(ch.find(word)!=ch.end()){
            ch[word]++;
        }
        else{
            ch[word]=1;
        }
    }
    f.close();
    
    for(map<string,int>::iterator it=ch.begin();it!=ch.end();++it){
        string wrd = it->first;
        int q = it->second;
        cout<<"word"<<wrd<<" is "<<(static_cast<double>(q)/total)<<"\n";
    }
}
