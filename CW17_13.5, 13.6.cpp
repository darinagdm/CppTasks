#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::stringstream;

int parseWords(string s, char del, int n, string words[]){
    stringstream sstream(s);
    string word;
    int k=0;
    while(std::getline(sstream,word,del) && k<n){
        words[k++] = word;
    }
    return k;
}

//13.5 - minimal words
string words_a(string s, char del){
    stringstream sstream(s);
    string word;
    int k=0;
    int min_word_len = INT_MAX;
    string min_word="";
    while(std::getline(sstream,word,del)){
        if(word.size()<min_word_len){
            min_word = word;
            min_word_len = word.size();
        }
    }
    return min_word;
}

//13.5 - minimal words
string words_b(string s, char del){
    stringstream sstream(s);
    string word;
    int k=0;
    int min_word_len = INT_MAX;
    string min_word="";
    while(std::getline(sstream,word,del)){
        if(word.size()<=min_word_len){
            min_word = word;
            min_word_len = word.size();
        }
    }
    return min_word;
}

//13.5 - minimal words
void words_c(string s, char del){
    stringstream sstream(s);
    stringstream sstream2(s);
    string word;
    int k=0;
    int min_word_len = INT_MAX;
    string min_word="";
    while(std::getline(sstream,word,del)){
        if(word.size()<min_word_len){
            min_word_len = word.size();
        }
    }
    while(std::getline(sstream,word,del)){
        if(word.size()==min_word_len){
            cout << "word = " << ",";
        }
    }
}

int main(){
    string text = "He said. The challenge Hector heard with joy, "
                "Then with his spear restrain`d the youth of Troy ";
    char del = ' ';
    /*vector<string> words{};
    stringstream sstream(text);
    string word;
    while(std::getline(sstream,word,del))
        words.push_back(word);
    for(const auto &str : words){
        cout << str << endl;
    }*/
    cout<<"First min len word = " << words_a(text,del)<<"\n";
    cout<<"Last min len word = " << words_b(text,del)<<"\n";
    words_c(text,del);
}
