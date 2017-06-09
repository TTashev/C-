#include <iostream>
#include <string>

using namespace std;

int occurences (string& text, string& search)
{
    int timesOccured = 0;
    for(int i = 0; i < text.length(); i++)
    {
        string temp = text.substr(i,search.length());
        if(temp == search)
        {
           timesOccured++;
        }
    }
    return timesOccured;
}

int main()
{
    string text;
    string search;
    getline(cin, text);
    getline(cin, search);

    cout << occurences(text, search) <<endl;
    return 0;
}
