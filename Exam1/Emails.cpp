#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string SearchWord;
    cin.sync_with_stdio(false);
    cin >> SearchWord;
    int PageSize, Occurences, CurrentPageSize;
    cin.sync_with_stdio(false);
    cin >> PageSize;
    string CurrentMessage;
    map<int, string > Messages;
    cin.sync_with_stdio(false);
    getline(cin, CurrentMessage);
    cin.clear();
    Occurences = CurrentPageSize = 0;
    while(CurrentMessage != ".")
    {
       stringstream ss(CurrentMessage);
       string word;
       while(ss >> word)
       {
           if(word == SearchWord) {Occurences++;}
       }

       Messages.insert( std::pair<int, string>(Occurences,CurrentMessage) );
       Occurences = 0;
       cin.sync_with_stdio(false);
       getline(cin, CurrentMessage);
    }
    cin.clear();
    for(std::map<int,string>::iterator it = Messages.end(); it != Messages.begin(); --it)
    {
         string c = it->second;
         if (c != ".")
         {
             std::cout << it->second << '\n';
         }
         PageSize--;
         if(PageSize < 0) {break;}
    }

    return 0;
}
