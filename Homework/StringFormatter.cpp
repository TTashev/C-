#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class StringFormatter
{
    public:
    string StringToFormat;
    string PrefixString;


    StringFormatter(string& stringToFormat, const string& FormatPrefix)
    {
        this->StringToFormat = stringToFormat;
        this->PrefixString = FormatPrefix;
    }
    void format(string insertArr[], int InsertArrSize)
    {
        istringstream s(this->StringToFormat);
        int counter = 0;

        for(int i = 0; i < StringToFormat.size(); i++)
        {
            string temp;
            temp = StringToFormat.substr(i,PrefixString.size());
            string StringToInsert = insertArr[counter];
            if(counter == InsertArrSize)
            {
                break;
            }
            if(temp == this->PrefixString)
            {
                StringToFormat.replace(i,PrefixString.length(), StringToInsert);
                counter++;
            }
        }
        cout << this->StringToFormat << endl;
    }
};


int main()
{
    string s = "Dear *:, Our company *: wants to make you a Donation Of *: Million *: in good faith. Please send us a picture of your credit card";
    StringFormatter formatter(s, "*:");
    string StringsToBeInserted[] = {"Ben Dover", "Totally Legit NonSpam Ltd","13", "Leva"};
    formatter.format(StringsToBeInserted, 4);
    //cout << s << endl;
    return 0;
}
