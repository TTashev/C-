#include <iostream>

using namespace std;

int const ArrSize = 100;
int main()
{
    int ElementsCount, Candidate, Longest, Count, Majorant;
    Majorant = 0;
    Candidate = 0;
    Longest = 0;
    Count = 1;
    cin >> ElementsCount;
    int Arr[ArrSize] = {};
    for(int i = 0; i < ElementsCount; i++)
    {
        cin >> Arr[i];
    }
    for(int j = 0; j < ElementsCount; j++)
    {
        if(Arr[j] == Arr[j + 1])
        {
            Candidate = Arr[j];
            Count++;
        }
        else
        {
           if(Longest < Count)
           {
               Longest = Count;
               Count = 1;
               Majorant = Candidate;
               Candidate = 0;
           }
        }
    }
    for(int k = 0; k < Longest; k++)
    {
        cout << Majorant << " ";
    }

    return 0;
}
