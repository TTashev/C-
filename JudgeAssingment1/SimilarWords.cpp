#include <iostream>
#include <string>
#include <math.h>
#include <set>

using namespace std;

//input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?' || input[i] == ';'

int main()
{
    string input, word, temp;
    int P, matchedLetters, SimilarWords;
    double percentage = 0;
    matchedLetters = SimilarWords = 0;
    set<char> setOfChars;
    getline(cin, input);
    cin >> word >> P;
    for(int i = 0; i < input.size(); i++)
    {
        if(isalpha(input[i]))
        {
            for(int a = i; a < input.size(); a++)
            {
                if(isalpha(input[a]) == false)
                {
                    temp = input.substr(i,a - i);
                    break;
                }
            }
            if(temp.size() == word.size() && temp[0] == word[0])
            {
                double ShorterString = fmax(word.size(), temp.size());
                for(int j = 0; j < ShorterString; j++)
                {
                   if(temp[j] == word[j])
                   {
                       setOfChars.insert(word[j]);
                       matchedLetters++;
                   }
                }
                percentage = (matchedLetters / ShorterString) * 100;
                if(percentage >= P)
                {
                   SimilarWords++;
                }
                matchedLetters = 0;
            }
        }
    }
    cout << SimilarWords <<endl;
    return 0;
}
