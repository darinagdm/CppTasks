#include <iostream>
#include <string> 
#include <cstdio>
#include <ctype.h>
using namespace std;

int main(){
    string str; 
    int words = 0, cons = 0;
    str = "Hello! How are you, Ann?";
    //cout << "Enter a string:\n";
    //getline(cin, str);
    for (int i = 0; i <= str.length(); i++){
        if (isalpha(str[i])){
            if(isupper(str[i])){
                str[i] = tolower(str[i]);
            }
            
            if((str[i]=='q')&&(str[i+1]=='q'))
            {
                cons++;
            }
            else if((str[i]=='w')&&(str[i+1]=='w'))
            {
                cons++;
            }
            else if((str[i]=='r')&&(str[i+1]=='r'))
            {
                cons++;
            }
            else if((str[i]=='t')&&(str[i+1]=='t'))
            {
                cons++;
            }
            else if((str[i]=='p')&&(str[i+1]=='p'))
            {
                cons++;
            }
            else if((str[i]=='s')&&(str[i+1]=='s'))
            {
                cons++;
            }
            else if((str[i]=='d')&&(str[i+1]=='d'))
            {
                cons++;
            }
            else if((str[i]=='f')&&(str[i+1]=='f'))
            {
                cons++;
            }
            else if((str[i]=='g')&&(str[i+1]=='g'))
            {
                cons++;
            }
            else if((str[i]=='h')&&(str[i+1]=='h'))
            {
                cons++;
            }
            else if((str[i]=='j')&&(str[i+1]=='j'))
            {
                cons++;
            }
            else if((str[i]=='k')&&(str[i+1]=='k'))
            {
                cons++;
            }
            else if((str[i]=='l')&&(str[i+1]=='l'))
            {
                cons++;
            }
            else if((str[i]=='z')&&(str[i+1]=='z'))
            {
                cons++;
            }
            else if((str[i]=='x')&&(str[i+1]=='x'))
            {
                cons++;
            }
            else if((str[i]=='c')&&(str[i+1]=='c'))
            {
                cons++;
            }
            else if((str[i]=='v')&&(str[i+1]=='v'))
            {
                cons++;
            }
            else if((str[i]=='b')&&(str[i+1]=='b'))
            {
                cons++;
            }
            else if((str[i]=='n')&&(str[i+1]=='n'))
            {
                cons++;
            }
            else if((str[i]=='m')&&(str[i+1]=='m'))
            {
                cons++;
            }
        }
        if (str[i] == ' ' || str[i] == '\0'){
           words++;
        }
    }

    cout << "Number of words: " << words << "\n";
    cout << "Number of words with double consonants: " << cons << "\n";
    cout << "Percentage: " << (float(cons)/float(words)) * 100 << "\n";
    return 0;
}
