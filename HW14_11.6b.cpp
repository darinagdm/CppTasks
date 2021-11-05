#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
 
using namespace std;
 
int main()
{ 
    ofstream fout("output.txt");
    int N, k;
    cout << "Enter how many numbers to write to the file: " << endl;
    cout << "N = ";
    cin >> N;
    cout << "The numbers are written to the file output.txt." << endl;
    int A[N];
    fout << "Random numbers:" << endl;
    k = 0;
    
    for (int i = 0; i < N; i++){  
        A[i] = rand() % 101;
        if (((int)sqrt(A[i]) == sqrt(A[i])) && (A[i] % 2)) k++;
        fout << A[i] << " ";
    }
    
    fout << endl << "Total number of odd squares: " << k << endl;
    fout.close();
    return 0;   
}
