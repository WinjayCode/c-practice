#include <iostream>
using namespace std;

// ʹ�� if...else
static void method1()
{
    int n;

    cout << "����һ������: ";
    cin >> n;

    if (n % 2 == 0)
        cout << n << " Ϊż����";
    else
        cout << n << " Ϊ������";
}

// ʹ����Ԫ�����
static void method2()
{
    int n;

    cout << "����һ������: ";
    cin >> n;

    (n % 2 == 0) ? cout << n << "  Ϊż����" : cout << n << " Ϊ������";
}

// �ж�һ��������������ż��
int main2()
{
    method1();

    //method2();

    return 0;
}