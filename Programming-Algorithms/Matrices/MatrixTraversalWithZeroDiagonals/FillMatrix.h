#ifndef FILLMATRIX_H
#define FILLMATRIX_H

#define MAX 20
void FillMatrix(unsigned a [MAX][MAX], unsigned n)
{
    int FillNum = 1;
    static int CurrRow = 1;
    for(int CurrCol = 0; CurrCol < n; CurrCol++)
    {
        while(CurrRow < n)
        {
            a[CurrRow][CurrCol] = FillNum;
            CurrRow++;
            FillNum++;
        }
        CurrRow = CurrCol + 2;
    }
    CurrRow = n - 2;
    for(int CurrCol = n - 1; CurrCol >= 1; CurrCol--)
    {
        while(CurrRow >= 0)
        {
            a[CurrRow][CurrCol] = FillNum;
            CurrRow--;
            FillNum++;
        }
        CurrRow = CurrCol - 2;
    }
}
#endif // FillMatrix
