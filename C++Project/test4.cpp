#include <iostream>
using namespace std;

// 使用 if
static void method1()
{
    float n1, n2, n3;

    cout << "请输入三个数: ";
    cin >> n1 >> n2 >> n3;

    if (n1 >= n2 && n1 >= n3)
    {
        cout << "最大数为: " << n1;
    }

    if (n2 >= n1 && n2 >= n3)
    {
        cout << "最大数为: " << n2;
    }

    if (n3 >= n1 && n3 >= n2) {
        cout << "最大数为: " << n3;
    }
}

// 使用 if...else
static void method2()
{
    float n1, n2, n3;

    cout << "请输入三个数: ";
    cin >> n1 >> n2 >> n3;

    if ((n1 >= n2) && (n1 >= n3))
        cout << "最大数为: " << n1;
    else if ((n2 >= n1) && (n2 >= n3))
        cout << "最大数为: " << n2;
    else
        cout << "最大数为: " << n3;
}

// 使用内嵌的 if...else
static void method3()
{
    float n1, n2, n3;

    cout << "请输入三个数: ";
    cin >> n1 >> n2 >> n3;

    if (n1 >= n2)
    {
        if (n1 >= n3)
            cout << "最大数为: " << n1;
        else
            cout << "最大数为: " << n3;
    }
    else
    {
        if (n2 >= n3)
            cout << "最大数为: " << n2;
        else
            cout << "最大数为: " << n3;
    }
}

// 判断三个数中的最大数
int main4()
{
    method1();
    //method2();
    //method3();

    return 0;
}