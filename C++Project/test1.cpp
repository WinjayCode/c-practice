#include <iostream>
using namespace std;

// 使用临时变量
static void method1()
{
    int a = 5, b = 10, temp;

    cout << "交换之前：" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\n交换之后：" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

// 不使用临时变量
static void method2()
{
    int a = 5, b = 10;

    cout << "交换之前：" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "\n交换之后：" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

// 交换两个数
int main()
{
    method1();

    //method2();

    return 0;
}