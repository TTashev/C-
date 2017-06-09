//Write a function that calculates the Nth Fibonacci number. For this task, you are NOT allowed to use any type of loop.

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double fibonacci = (pow(1 + sqrt(5),n) - pow(1 - sqrt(5),n)) / (pow(2,n) * sqrt(5));
    cout << fibonacci << endl;
    return 0;
}
