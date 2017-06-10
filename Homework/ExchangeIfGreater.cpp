#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}
