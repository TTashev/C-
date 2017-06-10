#include <iostream>

using namespace std;

void SelectionSort(int arr[], int start, int end, int arrSize)
{
   int temp = 0;
   for(int j = start; j < end; j++)
   {
       temp = j;
       for(int k = j + 1; k < end; k++)
       {
          if(arr[k] < arr[temp])
          {
             temp = arr[k];
             arr[k] = arr[j];
             arr[j] = temp;
          }
       }
   }
   for(int l = 0; l < arrSize; l++)
   {
       cout << arr[l] << " ";
   }
}

int const MAXSIZE = 100;
int main()
{
    int arrSize, start, end;
    cin >> arrSize;
    int arr[MAXSIZE] = {};
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }
    cin >> start >> end;
    if(start < 0 || end > arrSize)
    {
        cout << "Outside of the bounds of the array"
    }
    else
    {
        SelectionSort(arr, start, end, arrSize);
    }
    return 0;
}
