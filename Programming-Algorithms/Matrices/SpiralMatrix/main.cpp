#include <iostream>
#include <stdio.h>

#define MAX 5
using namespace std;

PrintMatrix(int matrix[MAX][MAX])
{
    for(int row = 0; row < MAX; row++)
    {
        for(int col = 0; col < MAX; col++)
        {
            if(row == MAX - 1 && matrix[row][col] < 10)
            {
                cout << "" << matrix[row][col] << "  ";
            }
            else
            {
                cout << matrix[row][col] << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    int LeftColumn, BottomRow, RightColumn, TopRow;
    LeftColumn = TopRow = 0;
    BottomRow = RightColumn = MAX - 1;
    int CurrentOffset = 1;
    int StartOffset = 0;
    int FillNum = 1;
    int matrix[MAX][MAX] = {};
    bool isFillNumBiggerThanSize = FillNum >= (MAX * MAX);

    while(FillNum <= (MAX * MAX))
    {
        if(FillNum > (MAX * MAX)) {break;}
        if(FillNum == (MAX * MAX))
        {
            for(int i = StartOffset; i <= MAX - CurrentOffset; i++)
            {
                matrix[i][LeftColumn] = FillNum;
                FillNum++;
                if(FillNum >= (MAX * MAX)) {break;}
            }
        }
        for(int i = StartOffset; i < MAX - CurrentOffset; i++)
        {
            matrix[i][LeftColumn] = FillNum;
            FillNum++;
            if(FillNum >= (MAX * MAX)) {break;}
        }
        if(FillNum >= (MAX * MAX)) {break;}
        for(int i = StartOffset; i < MAX - CurrentOffset; i++)
        {
            matrix[BottomRow][i] = FillNum;
            FillNum++;
        }
        for(int i = MAX - StartOffset - 1; i >= CurrentOffset; i--)
        {
            matrix[i][RightColumn] = FillNum;
            FillNum++;
        }
        for(int i = MAX - StartOffset - 1; i >= CurrentOffset; i--)
        {
            matrix[TopRow][i] = FillNum;
            FillNum++;
        }
        LeftColumn++;
        BottomRow--;
        RightColumn--;
        TopRow++;
        CurrentOffset++;
        StartOffset++;
    }
    PrintMatrix(matrix);

    return 0;
}
