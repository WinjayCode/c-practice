#include <iostream>
using namespace std;

// ʹ����ʱ����
static void method1()
{
    int a = 5, b = 10, temp;

    cout << "����֮ǰ��" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\n����֮��" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

// ��ʹ����ʱ����
static void method2()
{
    int a = 5, b = 10;

    cout << "����֮ǰ��" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "\n����֮��" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

// ����������
int main()
{
    method1();

    //method2();

    return 0;
}