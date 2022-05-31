#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void check_tags(const char* filename) {
    ifstream finp(filename);
    if (!finp.good())
        exit(1);

    while (finp.good()) {
        string s;
        getline(finp, s);
        if (finp.fail())
            break;

        int td = 0;
        int i = 0;
        int j1, j2;
        while (i < s.length()) {
            j1 = s.find("<td>", i);
            j2 = s.find("</td>", i);
            if (j1 != -1 && j2 != -1 && j1 < j2) {
                td++;
                i = j1 + 4;
            }
            else if (j1 != -1 && j2 != -1 && j2 < j1) {
                td--;
                i = j2 + 5;
            }
            else if (j1 != -1 && j2 == -1) {
                td++;
                i = j1 + 4;
            }
            else if (j1 == -1 && j2 != -1) {
                td--;
                i = j2 + 5;
            }
            else
                break;

            if (td < 0)
                break;
        }
        cout << s << endl;
        cout << boolalpha << (td == 0) << endl;
    }
    finp.close();
}

int main() {
    check_tags("input.txt");
    return 0;
}
