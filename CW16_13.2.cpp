#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int stops(string &s){
    size_t p1 = s.find(".");
    if(p1==string::npos){
        size_t len = s.length();
        while(s.length()>0 && isspace(s[0])){
            s.erase(0, 1);
        }
        return 0;
    }
    
    size_t p2 = s.rfind(".",p1-1);
    cout<<"p2="<<p2;
    if(p2==string::npos){
        s.erase(0,p1-1);
        return 1;
    }
    
    s.erase(p1,p2+1-p1);
    return 2;
}

int main(){
    string test[]={"fgdsf.guhqho.dj", "uegd.ud", "sgvs"};
    for(int i=0; i<3; ++i){
        stops(test[i]);
        cout << test[i] << endl;
    }
    string s;
    getline(cin,s);
    stops(s);
    cout<<s;
}
