#include <iostream>
using namespace std;

class Matrix
{
private:
    int a[2][2];

public:
    void getData()
    {
        cout << "Enter 4 elements: ";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    Matrix operator+(Matrix obj)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + obj.a[i][j];
            }
        }

        return temp;
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix A, B, C;

    cout << "Enter first matrix:\n";
    A.getData();

    cout << "Enter second matrix:\n";
    B.getData();

    C = A + B;

    cout << "Sum of matrices:\n";
    C.display();

    return 0;
}