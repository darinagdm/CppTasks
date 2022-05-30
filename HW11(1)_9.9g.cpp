#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int** Create(int row, int col)
{
    int** arr;
    arr = new int * [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    return arr;
}

void Fill(int** arr, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

void Show(int** arr, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Del(int** arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
int** Add_Col(int** arr, int height, int& width)
{
    int** arr_1;
    int pos = width;
    arr_1 = Create(height, width + 1);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < pos; j++)
        {
            arr_1[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - pos; j++)
        {
            arr_1[i][j + pos + 1] = arr[i][j + pos];
        }

    }
    width++;
    for (int i = 0; i < height; i++)
    {
        for (int j = pos; j < pos + 1; j++)
        {
            arr_1[i][j] = rand() % 100;
        }

    }
    Del(arr, height);
    arr = arr_1;
    return arr;
}

int main()
{
    int width, height;
    cout << "Enter width\n"; cin >> width;
    cout << "Enter hight\n"; cin >> height;
    int** arr;
    arr = Create(height, width);
    Fill(arr, height, width);
    Show(arr, height, width);
    arr = Add_Col(arr, height, width);
    Show(arr, height, width);
    Del(arr, height);
}
