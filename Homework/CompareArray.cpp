#include <iostream>

using namespace std;

bool CompArr(int FirstArr[], int SecondArr[],int FirstArraySize, int SecondArraySize)
{
   int ShortestArray = 0;
   if(FirstArraySize > SecondArraySize)
   {
     ShortestArray = SecondArraySize;
   }
   else
   {
     ShortestArray = FirstArraySize;
   }
   for(int k = 0; k < ShortestArray; k++)
   {
      if(FirstArr[k] != SecondArr[k])
      {
          return false;
      }
   }
   return true;
}

int const ArrSize = 100;
int main()
{
    int FirstArrSize, SecondArrSize;
    cin>>FirstArrSize;
    int FirstArr[ArrSize] = {};
    for(int i = 0; i < FirstArrSize; i++)
    {
        cin>>FirstArr[i];
    }
    cin>>SecondArrSize;
    int SecondArr[ArrSize] = {};
    for(int j = 0; j < SecondArrSize; j++)
    {
        cin>>SecondArr[j];
    }
    cout<< CompArr(FirstArr, SecondArr, FirstArrSize, SecondArrSize);

    return 0;
}
