#include <iostream>

using namespace std;

int main()
{
    unsigned long int n, factorial;
    int p = 5;
    int ZeroCount = 0;
    cin >> n;
    while(n >= p)
    {
        ZeroCount += (n / p);
        p *= 5;
    }
    cout << ZeroCount << endl;
    return 0;
}
