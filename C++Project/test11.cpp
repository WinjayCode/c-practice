#include <iostream>
using namespace std;

static void method1()
{
    int n1, n2, max;

    cout << "����������: ";
    cin >> n1 >> n2;

    // ��ȡ������
    max = (n1 > n2) ? n1 : n2;

    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);
}

// ��С������=(n1 * n2) / ���Լ��
static void method2()
{
    int n1, n2, hcf, temp, lcm;

    cout << "����������: ";
    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;

    // ����������Լ��
    while (hcf != temp)
    {
        if (hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    // ��ʽ
    lcm = (n1 * n2) / hcf;

    cout << "LCM = " << lcm;
}

// ��������С������
int main11()
{
    method1();
    //method2();

    return 0;
}