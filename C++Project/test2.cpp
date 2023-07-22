#include <iostream>
using namespace std;

// 使用 if...else
static void method1()
{
    int n;

    cout << "输入一个整数: ";
    cin >> n;

    if (n % 2 == 0)
        cout << n << " 为偶数。";
    else
        cout << n << " 为奇数。";
}

// 使用三元运算符
static void method2()
{
    int n;

    cout << "输入一个整数: ";
    cin >> n;

    (n % 2 == 0) ? cout << n << "  为偶数。" : cout << n << " 为奇数。";
}

// 判断一个数是奇数还是偶数
int main2()
{
    method1();

    //method2();

    return 0;
}