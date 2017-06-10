#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    bool IsSignFound = false;
    if(a > 0 && b > 0 && c > 0)
    {
       cout << "+" << endl;
       IsSignFound = true;
    }
    else
    {
       if(a < 0 && b < 0 && c > 0)
       {
          cout << "+" << endl;
          IsSignFound = true;
       }
       if(a < 0 && c < 0 && b > 0)
       {
          cout << "+" << endl;
          IsSignFound = true;
       }
       if(c < 0 && b < 0 && a > 0)
       {
          cout << "+" << endl;
          IsSignFound = true;
       }
       if(a < 0 || b < 0 || c < 0)
       {
           if(IsSignFound == false)
           {
              cout << "-" << endl;
           }
       }
    }
    return 0;
}
