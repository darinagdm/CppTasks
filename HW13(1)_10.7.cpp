#include <iostream>
using namespace std;

struct CARS {
    int ages;
    int cost;
};

int main(){
    CARS box[20];
    int n,iCost=0,iNums=0;
    cout<<"enter the number of cars: ";
    cin>>n;
    cout<<"enter ages & cost: \n";
    for(int i=0;i<n;i++)
    {
        cin>>box[i].ages;
        cin>>box[i].cost;
    }
    for(int i=0;i<n;i++)
    if (box[i].ages >= 5)
    {
        iCost=iCost+box[i].cost;
        ++iNums;
    }
    float AverageCost;
    AverageCost=iCost/iNums;
    cout<<AverageCost<<"\n";
    return 0;
}
