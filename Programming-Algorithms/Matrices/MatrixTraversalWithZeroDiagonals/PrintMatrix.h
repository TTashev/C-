#ifndef PRINTMATRIX_H
#define PRINTMATRIX_H

void PrintMatrix(unsigned a [MAX][MAX], unsigned n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            std::cout << a[row][col] << + " ";
        }
        std::cout << std::endl;
    }
}
#endif // PrintMatrix
