#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    cin >> input;
    map<int, vector<string> > transmissions;
    map<string, int> WordsOccurences;
    std::map<int,vector<string> >::iterator it;
    while(input != ".")
    {
        if(WordsOccurences.find(input) == WordsOccurences.end())
        {
            WordsOccurences[input] = 0;
        }
        WordsOccurences[input]++;
        cin.clear();
        cin >> input;
    }
    std::map<string,int>::iterator word;
    for(word = WordsOccurences.begin(); word != WordsOccurences.end(); word++)
    {
        string CurrWord = word->first;
        int occurences = word->second;
        transmissions[occurences].push_back(CurrWord);
    }
    int numberOfQuerries, occurrenceCount, index;
    cin >> numberOfQuerries;
    for(int i = 0; i < numberOfQuerries; i++)
    {
        cin >> occurrenceCount >> index;
        it = transmissions.find(occurrenceCount);
        if(it == transmissions.end())
        {
            cout << "." <<endl;
        }
        else
        {
            vector<string> & words = transmissions[occurrenceCount];
            sort(words.begin(), words.end());
            cout << transmissions[occurrenceCount][index] << endl;
        }
    }
    return 0;
}
