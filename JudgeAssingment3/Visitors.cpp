#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    istringstream manipulation (input);
    string temp;
    string id;
    string name;
    int age = 0;
    map<string, int> IDtoName;
    map<string, int> NumberOfEntries;
    multiset<int> Ages;
    manipulation >> temp;
    while(1)
    {
       if(temp == "end")
       {
           break;
       }
       else if(temp == "entry")
       {
           istringstream PersonInfo (input);
           string dump;
           PersonInfo >> dump;
           PersonInfo >> id;
           PersonInfo >> name;
           PersonInfo >> age;
           std::map<string, int>::iterator it;
           std::map<string, int>::iterator NameIt;
           it = NumberOfEntries.find(id);
           NameIt = IDtoName.find(name);
           if(it == NumberOfEntries.end())
           {
               NumberOfEntries[id] = 1;
               if(NameIt == IDtoName.end())
               {
                   IDtoName[name] = 1;
               }
               if(NameIt != IDtoName.end())
               {
                   NameIt->second++;
               }

               Ages.insert(age);
           }
           else
           {
               it->second++;
           }
       }
       else if(temp == "name")
       {
           istringstream PersonInfo (input);
           string dump;
           PersonInfo >> dump;
           PersonInfo >> name;
           std::map<string, string>::iterator it;
           bool IsInTheList = false;
           int counter = 0;
           std::map<string, int>::iterator NameIt;
           NameIt = IDtoName.find(name);
           if(NameIt == IDtoName.end())
           {
               cout << 0 << endl;
           }
           if(NameIt != IDtoName.end())
           {
               cout <<  NameIt->second << endl;
           }
       }
       else if(temp == "age")
       {
           istringstream PersonInfo (input);
           string dump;
           PersonInfo >> dump;
           int FirstAgeRange, SecondAgeRange;
           FirstAgeRange = SecondAgeRange = 0;
           PersonInfo >> FirstAgeRange;
           PersonInfo >> SecondAgeRange;
           int counter = 0;
           std::multiset<int>::iterator AgesIt;
           for(AgesIt = Ages.begin(); AgesIt != Ages.end();AgesIt++)
           {
               if((*AgesIt) >= SecondAgeRange)
               {
                   break;
               }
               else if((*AgesIt) >= FirstAgeRange && (*AgesIt) < SecondAgeRange)
               {
                   counter++;
               }
           }
        cout << counter << endl;
        counter = 0;
       }
       getline(cin, input);
       istringstream manipulation (input);
       manipulation >> temp;
    }
    return 0;
}
