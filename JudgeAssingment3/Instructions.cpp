#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string temp;
    cin >> temp;
    int InputInt = 0;
    vector<int> ResultNums;
    istringstream command (temp);
    while(temp != "end")
    {
        istringstream command (temp);
        if(command >> InputInt)
        {
            ResultNums.push_back(InputInt);
        }
        else
        {
            command >> temp;
            if(temp == "sum")
            {
                if(ResultNums.size() > 1)
                {
                    int firstNum = ResultNums[ResultNums.size() - 1];
                    ResultNums.pop_back();
                    int secondNum = ResultNums[ResultNums.size() - 1];
                    ResultNums.pop_back();
                    int sum = firstNum + secondNum;
                    ResultNums.push_back(sum);
                }
            }
            if(temp == "subtract")
            {
                if(ResultNums.size() > 1)
                {
                    int a = ResultNums[ResultNums.size() - 1];
                    ResultNums.pop_back();
                    int b = ResultNums[ResultNums.size() - 1];
                    ResultNums.pop_back();
                    int result = a - b;
                    ResultNums.push_back(result);
                }
            }
            if(temp == "concat")
            {
                if(ResultNums.size() > 1)
                {
                    string resultString;
                    ostringstream ss;
                    ss.clear();
                    int first = ResultNums[ResultNums.size() - 1];
                    ResultNums.pop_back();
                    int second = ResultNums[ResultNums.size() - 1];
                    ss << second;
                    resultString = ss.str();
                    ss.clear();
                    ss << first;
                    resultString = ss.str();
                    ResultNums.pop_back();
                    istringstream concat (resultString);
                    int ConcatResult;
                    concat >> ConcatResult;
                    ResultNums.push_back(ConcatResult);
                }

            }
            if(temp == "discard")
            {
                if(ResultNums.size() > 0)
                {
                    ResultNums.pop_back();
                }
            }
        }
        cin >> temp;
    }
    for(int i = 0; i < ResultNums.size(); i++)
    {
        cout << ResultNums[i] << endl;
    }
    return 0;
}
