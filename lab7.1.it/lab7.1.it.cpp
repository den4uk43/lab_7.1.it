
#include <iostream> 
#include <iomanip> 
#include <time.h> 
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -34;
    int High = 26;

    int rowCount = 8;
    int colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    //1)сформувати та вивести почткову матрицю
    Create(a, rowCount, colCount, Low, High);
    cout << "start matricha (8x6): " << endl;
    Print(a, rowCount, colCount);

    //2)впорядкувати стовпчики відповідно до завдання
    Sort(a, rowCount, colCount);
    cout << "matricha after sorting: " << endl;
    Print(a, rowCount, colCount);

    //3)обчислити S,k та замінити відповідні елементи нулями
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    cout << "\nmod matricha(retake 0): " << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((a[0][j1] < a[0][j1+1])
                ||
                (a[0][j1] == a[0][j1+1] &&
                    
                    a[1][j1] < a[1][j1+1])
                ||
                (a[0][j1] == a[0][j1+1] &&
                    a[1][j1] == a[1][j1+1] &&
                    a[2][j1] < a[2][j1+1]))
                Change(a, rowCount, j1, j1+1);
}

void Change(int** a, const int rowCount, const int col1, const int col2)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] >0 || (a[i][j] % 2 != 0))//всі додатні або не парні
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}