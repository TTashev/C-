#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text, Find, Replace;
    getline(cin, text);
    getline(cin, Find);
    getline(cin, Replace);
    //size_t start_pos = text.find(Find,Find.length());
    //text.replace(start_pos, Find.length(),Replace);
    for(int i = 0; i < text.length(); i++)
    {
        string temp;
        temp = text.substr(i, Find.length());
        if(temp == Find)
        {
            text.replace(i, Find.length(), Replace);
        }
    }
    cout << text << endl;
    return 0;
}
