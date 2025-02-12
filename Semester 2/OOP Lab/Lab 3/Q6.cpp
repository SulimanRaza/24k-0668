#include <iostream>
#include <string>
using namespace std;

class Matrix
{
    int row, column;
    int **m;

public:
    Matrix(int row, int column)
    {
        this->row = row;
        this->column = column;
        m = new int *[row];
        for (int i = 0; i < row; i++)
        {
            m[i] = new int[column];
        }
    }

    int getrow()
    {
        return row;
    }

    int getcolumn()
    {
        return column;
    }

    void setelements(int i, int j, int element)
    {
        if (i >= 0 && i < row && j >= 0 && j < column)
        {
            m[i][j] = element;
        }
        else
        {
            cout << "invalid index";
        }
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix &mat)
    {
        if (row != mat.getrow() || column != mat.getcolumn())
        {
            cout << "Can not add matrix..." << endl;
            exit(0);
        }
        Matrix result(row, column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result.setelements(i, j, m[i][j] + mat.m[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(Matrix &mat)
    {
        if (column != mat.getrow())
        {
            cout << "Can not multiply matrix..." << endl;
            exit(0);
        }
        Matrix result(row, mat.getcolumn());
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < mat.getcolumn(); j++)
            {
                result.setelements(i, j, 0);
                for (int k = 0; k < column; k++)
                {
                    result.m[i][j] += m[i][k] * mat.m[k][j];
                }
            }
        }
        return result;
    }

    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] m[i];
        }
        delete[] m;
    }
};

int main(int argc, char *argv[])
{
    int row1 = stoi(argv[1]);
    int column1 = stoi(argv[2]);
    int row2 = stoi(argv[3]);
    int column2 = stoi(argv[4]);

    Matrix m1(row1, column1);
    Matrix m2(row2, column2);

    int index = 5;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            m1.setelements(i, j, stoi(argv[index++]));
        }
    }

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            m2.setelements(i, j, stoi(argv[index++]));
        }
    }

    cout << "Matrix 1:\n";
    m1.display();

    cout << "Matrix 2:\n";
    m2.display();

    cout << "Matrix 1 + Matrix 2:\n";
    m1.add(m2).display();

    cout << "Matrix 1 * Matrix 2:\n";
    m1.multiply(m2).display();

    return 0;
}