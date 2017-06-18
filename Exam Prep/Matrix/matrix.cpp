#include "matrix.h"
#include <sstream>

#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows(rows),
    columns(cols),
    data(initRowsCols(rows, cols)) {
}

Matrix::Matrix(const Matrix& other) :
    rows(other.rows),
    columns(other.columns),
    data(initRowsCols(other.rows, other.columns)) {

    copyData(other.data, other.rows, other.columns,
             // NOTE: columns and rows now match between this and other, but writing it out for consistency:
             this->data, this->rows, this->columns);
}

unsigned int Matrix::getRows() const
{
    return this->rows;
}

unsigned int Matrix::getColumns() const
{
    return this->columns;
}

void Matrix::changeSize(unsigned int rows, unsigned int columns)
{
    if(rows > this->rows || columns > this->columns)
    {
        RowsCols newData = new DataType*[rows];
        for(int i = 0; i < rows; i++)
        {
            newData[i] = new DataType[columns];
            for(int j = 0; j < columns; j++)
            {
                newData[i][j] = 0;
            }
        }
        Matrix::copyData(this->data, this->rows, this->columns, newData, rows, columns);
        Matrix::freeRowsCols(this->data, this->rows);

        this->data = newData;
        this->rows = rows;
        this->columns = columns;
    }
    if(rows < this->rows || columns < this->columns)
    {
        RowsCols newData = new DataType*[rows];
        for(int i = 0; i < rows; i++)
        {
            newData[i] = new DataType[columns];
            for(int j = 0; j < columns; j++)
            {
                newData[i][j] = 0;
            }
        }
        Matrix::copyData(this->data, this->rows, this->columns, newData, rows, columns);
        Matrix::freeRowsCols(this->data, this->rows);

        this->data = newData;
        this->rows = rows;
        this->columns = columns;
    }

}

DataType Matrix::get(unsigned int row, unsigned int column) const
{
    Matrix::ensureInBounds(row, column);
    return this->data[row][column];
}

void Matrix::set(unsigned int row, unsigned int column, DataType value)
{
    Matrix::ensureInBounds(row, column);
    this->data[row][column] = value;
}

std::string Matrix::toString() const
{
    std::ostringstream stream;
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->columns; j++)
        {
            stream << this->data[i][j] << '\t';
        }
        stream << '\n';
    }
    return stream.str();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        freeRowsCols(this->data, this->rows);

        this->rows = other.rows;
        this->columns = other.columns;

        this->data = initRowsCols(other.rows, other.columns);

        copyData(other.data, other.rows, other.columns,
                 this->data, this->rows, this->columns);
    }

    return *this;
}

Matrix::~Matrix()
{
    Matrix::freeRowsCols(this->data, this->rows);
}

void Matrix::ensureInBounds(unsigned int row, unsigned int column) const
{
    if (row < 0 || row >= this->rows
        || column < 0 || column >= this->columns) {
        throw std::range_error("Out of bounds");
    }
}

void Matrix::freeRowsCols(RowsCols data, unsigned int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
RowsCols Matrix::initRowsCols(unsigned int rows, unsigned int columns)
{
    RowsCols data;
    data = new Row[rows];
    for (unsigned int row = 0; row < rows; row++)
    {
        data[row] = new DataType[columns]{};
    }
    return data;
}
void Matrix::copyData(RowsCols source, unsigned int sourceRows, unsigned int sourceCols, RowsCols dest, unsigned int destRows, unsigned int destCols) {
    for (unsigned int row = 0; row < sourceRows & row < destRows; row++) {
        for (unsigned int col = 0; col < sourceCols & col < destCols; col++) {
            dest[row][col] = source[row][col];
        }
    }
}



