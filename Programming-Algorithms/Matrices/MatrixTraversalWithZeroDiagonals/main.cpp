#include <iostream>

#include "FillMatrix.h"
#include "PrintMatrix.h"

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    unsigned matrix[MAX][MAX] = {};

    FillMatrix(matrix,n);
    PrintMatrix(matrix, n);


    return 0;
}


