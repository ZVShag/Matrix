#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Matrix
{
    T** matrix;
    int m; //stroki
    int n; // stolbci
public:
    Matrix() { m = 0; n = 0; }
    Matrix(int a, int b)
    {
        //a[i][j]
        m = a;
        n = b;
        // выделение памяти под хранение матрицы
        matrix = (T**) new T * [m];// кол-во строк определяет кол-во указателей
        for (int i = 0; i < m; i++)
        {
            matrix[i] = (T*) new T[n];
        }// память выделена

        // заполнение матрицы 0
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;

    }


    T Get_element(int i, int j)
    {
        if ((i > -1) && (i < m) && (j > -1) && (j < n))
            return matrix[i][j];
        else
            return 0;
    }
    T Set_element(int i, int j, T c)
    {
        if ((i > -1) && (i < m) && (j > -1) && (j < n))
            matrix[i][j] = c;
        else
            return 0;
    }
    void Print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << "\t";
            cout << endl;
        }
    }
    bool operator ==(const Matrix& a)
    {
        return ((this->m == a.m) && (this->n == a.n));
    }
    int Get_min()
    {
        mn = matrix[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (matrix[i][j] < mn)
                    mn = matrix[i][j];
        }
        return mn;

    }
    ~Matrix()
    {
        for (int i = 0; i < m; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
};



int main()
{
    int n, m;
    cout << "Strok: ";
    cin >> m;
    cout << endl << "Stolb:  ";
    cin >> n;
    Matrix<int> mtx(m, n);// вызван конструктор с параметрами, все элементы =0
    mtx.Print();
    cout << endl;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mtx.Set_element(i, j, i + j);// заполнение по формуле
    mtx.Print();
    /*
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "mtx[" << i << "," << j << "] =  ";
            int d;
            cin >> d;
            cout << endl;
            mtx.Set_element(i, j, d);
        }
    mtx.Print();*/
    cout << endl;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mtx.Set_element(i, j, rand() % 100 - 50);
    mtx.Print();
}

