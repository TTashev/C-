#include <iostream>

using namespace std;

int main()
{
    int a,b, remainder;
    cin >> a >> b;
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while(remainder != 0)
    {
        remainder = b % a;
        b = a;
        a = remainder;
        if(b % a == 0)
        {
            break;
        }
    }

    cout << remainder << endl;
    return 0;
}
