#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, currNum, weight;
    cin >> n >> m;
    int inputArrays[n][m] = {};
    int ResultArr[m] = {};
    int weights[n] = {};
    for(int i = 0; i < n; i++)
    {
        for(int num = 0; num < m; num++)
        {
            cin >> currNum;
            inputArrays[i][num] = currNum;
        }
    }
    for(int j = 0; j < n; j++)
    {
        cin >> weight;
        weights[j] = weight;
    }
    int weightCounter = 0;
    for(int x = 0; x < m; x++)
    {
        for(int z = 0; z < n; z++)
        {
            ResultArr[x] += inputArrays[z][x] * weights[z];
        }
    }
    for(int res = 0; res < m; res++)
    {
        cout << ResultArr[res] << " ";
    }
    cout << endl;
    return 0;
}
