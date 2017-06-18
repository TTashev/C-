#include <iostream>
#include <sstream>

using namespace std;

int Measurement1[500] = {};
int Measurement2[500] = {};

int main()
{
    string firstInput;
    getline(cin, firstInput);
    stringstream FirstArr(firstInput);
    int ArrSizeCounter, CurrentNum;
    ArrSizeCounter = CurrentNum = 0;
    while(FirstArr >> CurrentNum)
    {
        Measurement1[ArrSizeCounter] = CurrentNum;
        ArrSizeCounter++;
    }
    int ArrSizeCounter2 = 0;
    string secondinput;
    getline(cin, secondinput);
    stringstream SecondArr(secondinput);
    while(SecondArr >> CurrentNum)
    {
        Measurement2[ArrSizeCounter2] = CurrentNum;
        ArrSizeCounter2++;
    }
    for(int i = 0; i < ArrSizeCounter; i++)
    {
        if(Measurement1[i] - Measurement2[i] == 1)
        {
            cout << Measurement2[i] << " ";
            continue;
        }
        else if(Measurement2[i] - (Measurement1[i] - Measurement2[i]) < 0)
        {
            cout << 0 << " ";
        }
        else if(Measurement2[i] - (Measurement1[i] - Measurement2[i]) >= 0)
        {
            cout << Measurement2[i] / (Measurement1[i] - Measurement2[i]) << " ";
        }
    }
    cout << endl;
    return 0;
}
