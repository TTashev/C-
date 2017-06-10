#include <iostream>

using namespace std;


 //103 -2 5 16 7
void SelectionSort(int arr[], int start, int endArr, int arrSize)
{
   int temp = 0;
   for(int j = start; j < endArr; j++)
   {
       temp = j;
       for(int k = j + 1; k < endArr; k++)
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
    int arrSize, start, endArr;
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    int arr[MAXSIZE] = {};
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the start and the end index from which the array must be sorted ";
    cin >> start >> endArr;
    if(start < 0 || endArr > arrSize)
    {
        cout << "Outside of the bounds of the array";
    }
    else
    {
        SelectionSort(arr, start, endArr, arrSize);
    }
    return 0;
}
