#include <iostream>
using namespace std;
template<class T>
class Matrix {
    T **matrix;
    int sizeOfrows=0;
    int sizeOfcolumns=0;
public:
    Matrix();
    Matrix(int sizeOfrows,int sizeOfcolumns);
    Matrix(const Matrix<T>&matrix1);
    Matrix<T> operator+(Matrix<T>&matrix1);
    Matrix<T> operator-(Matrix<T>&matrix1);
    Matrix<T> operator*(Matrix<T>&matrix1);
    void Transpose();
    template<class T1>
    friend istream& operator>>(istream& input,Matrix<T1>& matrix1);
    template<class T1>
    friend ostream& operator<<(ostream& input,const Matrix<T1>& matrix1);
};
template<class T>
Matrix<T>::Matrix()
{
    sizeOfrows=0;
    sizeOfcolumns=0;
}

template<class T>
Matrix<T>::Matrix(int sizeOfrows, int sizeOfcolumns)
{
    this->sizeOfrows=sizeOfrows;
    this->sizeOfcolumns=sizeOfcolumns;
    matrix=new T*[sizeOfrows];
    for (int rows = 0; rows < sizeOfrows; ++rows)
    {
        matrix[rows]=new T[sizeOfcolumns];
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &matrix1)
{
    if(matrix1.sizeOfrows == sizeOfrows&&matrix1.sizeOfcolumns == sizeOfcolumns){
    Matrix<T>matrix2(matrix1.sizeOfrows,matrix1.sizeOfcolumns);
    for (int rows = 0; rows < matrix1.sizeOfrows; ++rows)
    {
        for (int columns = 0; columns < matrix1.sizeOfcolumns; ++columns)
        {
            matrix2.matrix[rows][columns]=(this->matrix[rows][columns])+(matrix1.matrix[rows][columns]);
        }
    }
    return matrix2;
    }
    else
        cout<<"Please enter the same size for 2 matrices!\n";

}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &matrix1) {
    if(matrix1.sizeOfrows == sizeOfrows&&matrix1.sizeOfcolumns == sizeOfcolumns){
    Matrix<T>matrix2(matrix1.sizeOfrows,matrix1.sizeOfcolumns);
    for (int rows = 0; rows < matrix1.sizeOfrows; ++rows)
    {
        for (int columns = 0; columns < matrix1.sizeOfcolumns; ++columns)
        {
            matrix2.matrix[rows][columns]=(this->matrix[rows][columns])-(matrix1.matrix[rows][columns]);
        }
    }
    return matrix2;
    }
    else
        cout<<"Please enter the same size for 2 matrices!\n";

}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &matrix1) {
    if (sizeOfcolumns == matrix1.sizeOfrows)
    {
        Matrix<T> matrix2(this->sizeOfrows, matrix1.sizeOfcolumns);
        for (int rows = 0; rows < sizeOfrows; ++rows)
        {
            for (int columns = 0; columns < matrix1.sizeOfcolumns; ++columns)
            {
               matrix2.matrix[rows][columns]=0;
            }

        }
        for (int rows = 0; rows < sizeOfrows; ++rows)
        {
            for (int columns = 0; columns < matrix1.sizeOfcolumns; ++columns)
            {
                for (int i = 0; i <sizeOfcolumns ; ++i)
                {
                    matrix2.matrix[rows][columns] += (this->matrix[rows][i] * matrix1.matrix[i][columns]);
                }
            }
        }
        return matrix2;
    }

}


template<class T>
void Matrix<T>::Transpose()
{
    Matrix<T>matrix1(sizeOfcolumns,sizeOfrows);
    for (int rows = 0; rows < sizeOfrows; ++rows) {
        for (int columns = 0; columns < sizeOfcolumns; ++columns) {
            matrix1.matrix[columns][rows]=this->matrix[rows][columns];
        }

    }
    if (sizeOfrows!=sizeOfcolumns)
    {
        for (int i = 0; i < sizeOfrows; ++i) {
            delete[]matrix[i];

        }
        delete []matrix;
        matrix=new T*[sizeOfrows];
        for (int rows = 0; rows < sizeOfrows; ++rows)
        {
            matrix[rows]=new T[sizeOfcolumns];
        }
        this->sizeOfrows=matrix1.sizeOfrows;
        this->sizeOfcolumns=matrix1.sizeOfcolumns;
    }
    for (int rows = 0; rows < matrix1.sizeOfrows; ++rows) {
        for (int columns = 0; columns < matrix1.sizeOfcolumns; ++columns) {
            this->matrix[rows][columns]=matrix1.matrix[rows][columns];
        }

    }
}

template<class T1>
ostream &operator<<(ostream &output,const Matrix<T1> &matrix1)
{
    cout<<"Matrix is : "<<endl;
    for (int rows = 0; rows <matrix1.sizeOfrows ; rows++)
    {
        for (int columns = 0; columns < matrix1.sizeOfcolumns; columns++)
            output << matrix1.matrix[rows][columns] << " ";
        output<<endl;
    }
    return output;
}
template<class T1>
istream &operator>>(istream &input, Matrix<T1> &matrix)
{
    cout<<"Enter size of rows and columns:"<<endl;
    input>>matrix.sizeOfrows>>matrix.sizeOfcolumns;
    matrix.matrix=new T1*[matrix.sizeOfrows];
    for (int i = 0; i < matrix.sizeOfrows; i++)
    {
        matrix.matrix[i]=new T1[matrix.sizeOfcolumns];
    }
    for (int rows = 0; rows <matrix.sizeOfrows ; rows++){
        cout<<"Enter "<<matrix.sizeOfcolumns<<" numbers of row "<<rows+1<<endl;
        for (int columns = 0; columns <matrix.sizeOfcolumns ; columns++)
        {
            input>>matrix.matrix[rows][columns];
        }
    }
    return input;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &matrix1) {
    sizeOfrows=matrix1.sizeOfrows;
    sizeOfcolumns=matrix1.sizeOfcolumns;
    matrix=new T*[sizeOfrows];
    for (int rows = 0; rows < sizeOfrows; ++rows) {
        this->matrix[rows]=new T[sizeOfcolumns];
    }
    for (int rows = 0; rows < sizeOfrows; ++rows) {
        for (int columns = 0; columns < sizeOfcolumns; ++columns) {
            this->matrix[rows][columns]=matrix1.matrix[rows][columns];
        }

    }
}
