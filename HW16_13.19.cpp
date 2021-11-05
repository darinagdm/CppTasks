#include <iostream>
#include <string>
using namespace std;
 
string replaceLetters(string s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'z'){
            s[i] = 'a';
        }
        else{
            s[i] = (char)(s[i] + 1);
        }
    }
    return s;
}

int main(){
    string s = "abcdezFGHa";
    cout << replaceLetters(s);
    return 0;
}
