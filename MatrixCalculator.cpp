#include <iostream>
#include "Matrix.h"
using namespace std;
class MatrixCalculator
{
public:
    MatrixCalculator()
    {
        bool flag=true;
        while(flag)
        {
            cout<<"Welcome to FCI Matrix Calculator\n---------------------------"<<endl;
            cout<<"1- Perform Matrix Addition\n"
                  "2- Perform Matrix Subtraction\n"
                  "3- Perform Matrix Multiplication\n"
                  "4- Matrix Transpose\n"
                  "5- Exit"<<endl;
            int choise;
            Matrix<int>matrix1,matrix2;
            cin>>choise;
            switch (choise) {
                case 1:
                {
                    cout<<"Matrix 1 :";
                    cin>>matrix1;
                    cout<<"Matrix 2 :";
                    cin>>matrix2;
                    cout<<matrix1+matrix2;
                    break;
                }
                case 2:
                {
                    cout<<"Matrix 1 :";
                    cin>>matrix1;
                    cout<<"Matrix 2 :";
                    cin>>matrix2;
                    cout<<matrix1-matrix2;
                    break;
                }
                case 3:
                {
                    cout<<"Matrix 1 :";
                    cin>>matrix1;
                    cout<<"Matrix 2 :";
                    cin>>matrix2;
                    cout<<matrix1*matrix2;
                    break;
                }
                case 4:
                {
                    cin>>matrix1;
                    matrix1.Transpose();
                    cout<<matrix1;
                    break;
                }
                case 5:
                {
                    flag=false;
                    break;
                }
                default:
                    cout<<"wrong input\n";
                    break;
            }

        }
    }
};
int main()
{
    MatrixCalculator matrixCalculator;

}
