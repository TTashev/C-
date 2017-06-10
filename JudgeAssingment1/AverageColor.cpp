#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    string FirstColor, SecondColor, FirstTemp, SecondTemp;
    cin >> FirstColor >> SecondColor;
    cout << "#"<<"";
    for(int i = 1; i < FirstColor.size(); i+=2)
    {
       string FirstTemp = FirstColor.substr(i, 2);
       string SecondTemp = SecondColor.substr(i, 2);
       int x = strtoul(FirstTemp.c_str(), NULL, 16);
       int y = strtoul(SecondTemp.c_str(), NULL, 16);
       int average = (x + y) / 2;
       if(average == 0)
       {cout << "00"<<"";}
       else
       {
          stringstream stream;
          stream << hex << average;
          string  result( stream.str() );
          cout << result <<"";
       }
    }
    return 0;
}
