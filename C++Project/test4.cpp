#include <iostream>
using namespace std;

// ʹ�� if
static void method1()
{
    float n1, n2, n3;

    cout << "������������: ";
    cin >> n1 >> n2 >> n3;

    if (n1 >= n2 && n1 >= n3)
    {
        cout << "�����Ϊ: " << n1;
    }

    if (n2 >= n1 && n2 >= n3)
    {
        cout << "�����Ϊ: " << n2;
    }

    if (n3 >= n1 && n3 >= n2) {
        cout << "�����Ϊ: " << n3;
    }
}

// ʹ�� if...else
static void method2()
{
    float n1, n2, n3;

    cout << "������������: ";
    cin >> n1 >> n2 >> n3;

    if ((n1 >= n2) && (n1 >= n3))
        cout << "�����Ϊ: " << n1;
    else if ((n2 >= n1) && (n2 >= n3))
        cout << "�����Ϊ: " << n2;
    else
        cout << "�����Ϊ: " << n3;
}

// ʹ����Ƕ�� if...else
static void method3()
{
    float n1, n2, n3;

    cout << "������������: ";
    cin >> n1 >> n2 >> n3;

    if (n1 >= n2)
    {
        if (n1 >= n3)
            cout << "�����Ϊ: " << n1;
        else
            cout << "�����Ϊ: " << n3;
    }
    else
    {
        if (n2 >= n3)
            cout << "�����Ϊ: " << n2;
        else
            cout << "�����Ϊ: " << n3;
    }
}

// �ж��������е������
int main4()
{
    method1();
    //method2();
    //method3();

    return 0;
}