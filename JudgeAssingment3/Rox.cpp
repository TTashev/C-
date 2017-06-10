#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    char input;
    cin >> input;
    char CurrentDNA[5] = {};
    short counter = 0;
    set<string> DNA;
    set<string>::iterator itend;
    itend = DNA.end();
    while(input != '.')
    {
        CurrentDNA[counter] = input;
        counter++;
        if(counter == 5)
        {
            counter = 0;
            string temp(CurrentDNA, 5);
            if(DNA.find(temp) == itend)
            {
               DNA.insert(temp);
            }
            else
            {
               DNA.erase(temp);
            }
        }
        cin >> input;
    }
    set<string>::iterator it;
    for (it = DNA.begin(); it != DNA.end(); it++ )
    {
        cout << std::hex << (*it) << endl;
    }
    return 0;
}
