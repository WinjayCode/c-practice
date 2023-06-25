#include <iostream>
using namespace std;

/*
*
* *
* * *
* * * *
* * * * *
*/
static void method1()
{
    int rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/
static void method2()
{
    int rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

/*
A
B B
C C C
D D D D
E E E E E
*/
static void method3()
{
    char input, alphabet = 'A';

    cout << "输入最后一个大写字母: ";
    cin >> input;

    for (int i = 1; i <= (input - 'A' + 1); ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << alphabet << " ";
        }
        ++alphabet;

        cout << endl;
    }
}

/*
* * * * *
* * * *
* * *
* *
*
*/
static void method4()
{
    int rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = rows; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
static void method5()
{
    int rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = rows; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
*/
static void method6()
{
    int space, rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for (space = 1; space <= rows - i; ++space)
        {
            cout << "  ";
        }

        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
}

/*
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/
static void method7()
{
    int rows, count = 0, count1 = 0, k = 0;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int space = 1; space <= rows - i; ++space)
        {
            cout << "  ";
            ++count;
        }

        while (k != 2 * i - 1)
        {
            if (count <= rows - 1)
            {
                cout << i + k << " ";
                ++count;
            }
            else
            {
                ++count1;
                cout << i + k - 2 * count1 << " ";
            }
            ++k;
        }
        count1 = count = k = 0;

        cout << endl;
    }
}

/*
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/
static void method8()
{
    int rows;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = rows; i >= 1; --i)
    {
        for (int space = 0; space < rows - i; ++space)
            cout << "  ";

        for (int j = i; j <= 2 * i - 1; ++j)
            cout << "* ";

        for (int j = 0; j < i - 1; ++j)
            cout << "* ";

        cout << endl;
    }
}

/*
           1
         1   1
       1   2   1
     1   3   3    1
   1  4    6   4   1
 1  5   10   10  5   1
*/
static void method9()
{
    int rows, coef = 1;

    cout << "Enter number of rows: ";
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
            cout << "  ";

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            cout << coef << "   ";
        }
        cout << endl;
    }
}

/*
1
2 3
4 5 6
7 8 9 10
*/
static void method10()
{
    int rows, number = 1;

    cout << "输入行数: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << number << " ";
            ++number;
        }

        cout << endl;
    }
}

// 创建各类三角形图案
int main9()
{
    method1();
    
    return 0;
}