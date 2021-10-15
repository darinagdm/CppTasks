#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Введіть n:"<<endl;
    cin >> n;
    
    const int size = 2 * n + 1;
    int array[size][size];          
    int arrayimg[size][size]; 
    
    cout<<"Введіть матрицю порядку "<<size<<"x"<<size<<":"<<endl;

    for(int i=0;i<size;i++){                       
        for(int j=0;j<size;j++)
            cin>>array[i][j];
    }

    for(int i=0;i<size;i++){                       
        for(int j=0;j<size;j++){
            arrayimg[i][j]=array[i][size-1-j];        
        }
    }

    cout<<"Початкова матриця:"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<array[i][j]<<"\t";            
        cout<<endl;
    }

    cout<<"Дзеркально відображена матриця відносно вертикальної осі:"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<arrayimg[i][j]<<"\t";     
        cout<<endl;
    }
    return 0;
}
