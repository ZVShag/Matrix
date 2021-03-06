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
        matrix = (T**) new T* [m];// кол-во строк определяет кол-во указателей
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
    Matrix(const Matrix &a)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                this->matrix[i][j] = a.matrix[i][j];  
     

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

    T Get_min()
    {
        int mn = matrix[0][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] < mn)
                    mn = matrix[i][j];
        return mn;
    }

    T Get_max()
    {
        int mx = matrix[0][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] > mx)
                    mx = matrix[i][j];
        return mx;
    }
    void Set_from_formula()
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j]= j-i;

    }
    void Set_from_random()
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = rand() % 100 - 20;

    }
    void Set_from_hand()
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cout << "mtx[" << i << "," << j << "] =  ";
                int d;
                cin >> d;
                cout << endl;
                matrix[i][j]=d;
            }
    }
    bool operator ==(Matrix& a)
    {
        bool p = true;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != a.Get_element(i, j))
                {
                    p = false;
                  
                }
        return p;

    }
    void Determinant()
    {
        int gd=0;
        int pd=0;
        int tr1 = matrix[0][0];
        int tr2 = matrix[n-1][n-1];
        int tr3 = matrix[n - 1][0];
        int tr4 = matrix[0][n - 1];
        for (int i = 0; i < n; i++)
        {
            gd = gd + matrix[i][i];
            pd = pd + matrix[i][n - i-1];
            if ((i + 1) < n)
                tr1 = tr1 + matrix[i + 1][n - i - 1];
            if (n - 2 > 0)
                tr2 = tr2 + matrix[i][n - 2 - i];
            if ((i + 1) < n)
            {
                tr3 = tr3 + matrix[i][i + 1];
                cout << matrix[i][i + 1] << endl;
            }
            if ((i + 1) < n)
                tr4 = tr4 + matrix[i + 1][i];
        }
        cout << tr3  << endl;
        
    }
    bool operator !=(Matrix& a)
    {
        bool p = true;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != a.Get_element(i, j))
                {
                    p = false;
                    
                }
        return !p;

    }
    void Summmatrix(Matrix &a)
    {

        if (n == a.n && m == a.m)
        {
            Matrix<int> d(m, n);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    d.Set_element(i, j, matrix[i][j] + a.Get_element(i, j));
            
            d.Print();
        }
       
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
    //Создание матрицы 
    Matrix<int> mtx(m, n);
    Matrix<int> mtx2(m, n);
    //Вывод на экран болваник из конструктора

    //mtx.Print();
    cout << endl;
    
    //Матрица заполняется по формуле
    mtx.Set_from_formula();
    mtx.Print();
    cout << endl;
    
    //Заполнение матрицы вручную
    //mtx.Set_from_hand();
 
    //Заполнение матрицы рандомными числами
    //mtx2.Set_from_random();
    //mtx2.Print();
    cout << endl << "Min element:  " << mtx2.Get_min();
    cout << endl << "Max element:  " << mtx2.Get_max();
   
    if (mtx == mtx2)
    {
        cout << "ravno";
    }
    cout << endl;
    mtx.Print();
    cout << endl;
    mtx.Determinant();
    
  

}

