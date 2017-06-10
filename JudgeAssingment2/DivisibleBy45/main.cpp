#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

int main()
{
    string first, second;
    getline(cin, first);
    getline(cin, second);
    BigInt FirstNum(first);
    BigInt SecondNum(second);
    string endNum = SecondNum.getDigits();
    int num = 1;
    int sum = 0;
    string temp = FirstNum.getDigits();
    while(1)
    {
        for(int i = 0; i < temp.size(); i++)
        {
            sum += temp[i] - '0';
        }
        if(sum % 9 == 0 && (temp[temp.size() - 1] == '5' || temp[temp.size() - 1] == '0'))
        {
            cout << FirstNum << endl;
        }
        sum = 0;
        FirstNum += num;
        temp = FirstNum.getDigits();
        if(temp == endNum)
        {
            break;
        }
    }
    return 0;
}
