#include <iostream>
#include <fstream>
using namespace std;

class Polynom {
    private:
        int n;
        double* members;

    public:
        double &operator[](int i){
            return members[i];
        }
        friend ostream& operator<<(ostream &out, const Polynom &p) {
            for (int i = 0; i < p.n; i++) {
                if (i == 0) {
                    cout << p.members[i];
                    continue;
                } 
                
                else {
                    cout << " + " << p.members[i];
                }
                
                cout << "*x";
                if (i != 1) cout << "^" << i;
            }
        }

        friend istream &operator>>(istream &in, Polynom &p) {
            cout << "\nn = ";
            int item;
            cin >> item;
            p.n = item;
            p.members = (double*)malloc(sizeof(double)*p.n);
            for (int i=0; i<p.n; i++) {
                cout << "Member of degree " << i <<": ";
                cin >> p.members[i];
            }
        }

        Polynom(){};

        Polynom(int n, double* arr) {
            this->n = n;
            members = (double*)malloc(sizeof(double)*n);
            
            for (int i = 0; i < n; i++) {
                members[i] = arr[i];
            }
        };

        Polynom(const Polynom &p) {
            n = p.n;
            
            for (int i = 0; i < n; i++) {
                members[i] = p.members[i];
            }
        }

        ~Polynom(){free(members);};

        friend Polynom finPoly(const char* fname);
        friend void foutPoly(const char* fname, const Polynom &p);
};

Polynom finPoly(const char* fname) {
    FILE* file = fopen(fname, "rb");
    Polynom p;
    fread(&p.n, sizeof(p.n), 1, file);
    p.members = (double*)malloc(sizeof(double)*p.n);
    fread(&p.members, sizeof(p.members), 1, file);
    fclose(file);
    return p;
}


void foutPoly(const char* fname, const Polynom &p) {
    FILE* file = fopen(fname, "wb");
    fwrite(&p.n, sizeof(p.n), 1, file);
    fwrite(&p.members, sizeof(p.members), 1, file);
    fclose(file);
}


int main() {
    Polynom p1, p2;
    cin >> p1;
    foutPoly("15.3", p1);
    p2 = finPoly("15.3");
    cout << p2;
}
