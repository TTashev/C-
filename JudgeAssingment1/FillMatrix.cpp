#include <iostream>
#include <string>
#include <stack>

using namespace std;
void DepthFirstSearch(char** matrix, int x, int y, char prevC, char newC, int TotalRows, int TotalCols)
{

    if(x < 0 || x >= TotalRows || y < 0 || y >= TotalCols)
    {
        return;
    }

    if(matrix[x][y] != prevC)
    {
        return;
    }
    matrix[x][y] = newC;
    DepthFirstSearch(matrix, x + 1, y, prevC, newC, TotalRows, TotalCols);
    DepthFirstSearch(matrix, x - 1, y, prevC, newC, TotalRows, TotalCols);
    DepthFirstSearch(matrix, x, y + 1, prevC, newC, TotalRows, TotalCols);
    DepthFirstSearch(matrix, x, y - 1, prevC, newC, TotalRows, TotalCols);
}
void floodFill(char** matrix, int x, int y, char newC, int TotalRows, int TotalCols)
{
    char prevC = matrix[x][y];
    DepthFirstSearch(matrix, x, y, prevC, newC, TotalRows, TotalCols);
}

int main()
{
    int row, col, StartRow, StartCol;
    char FillChar, StartChar;
    cin >> row >> col;
    char** matrix = new char*[row];
    for(int colcount = 0; colcount < row; colcount++)
    {
       matrix[colcount] = new char[col];
    }
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
           cin >> matrix[r][c];
        }
    }
    cin >> FillChar;
    cin >> StartRow >> StartCol;
    StartChar = matrix[StartRow][StartCol];
    if(StartChar != FillChar && StartRow >= 0 && StartRow < row && StartCol >= 0 && StartCol < col)
    {
       floodFill(matrix,StartRow,StartCol,FillChar, row , col);
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
           cout << matrix[i][j];
        }
        cout << endl;
    }
    delete[] matrix;
    return 0;
}

