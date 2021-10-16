#include <iostream>

using namespace std;

struct ChessField{
    char hor;
    int vert;
};

void inp_field(ChessField* chf){
    do{
        cout << "Input horizontal coord (abcdefgh): ";
        cin >> chf->hor;
    } while (chf->hor > 'h' || chf->hor < 'a');
    
    do{
        cout << "Input vertical coord (abcdefgh): ";
        cin >> chf->vert;
    } while (chf->vert > 8 || chf->vert < 1);
    
}

void print_field(ChessField chf){
    cout << chf.hor << chf.vert << endl;
}

int main(){
    ChessField chf;
    inp_field(&chf);
    print_field(chf);
}
