#include <iostream>
using namespace std;

// ��һ�����Ľ׳�(һ���������Ľ׳ˣ�Ӣ�factorial��������С�ڼ����ڸ������������Ļ�������0�Ľ׳�Ϊ1����Ȼ��n�Ľ׳�д��n!��)
int main8()
{
    unsigned int n;
    unsigned long long factorial = 1;

    cout << "����һ������: ";
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }

    cout << n << " �Ľ׳�Ϊ��" << " = " << factorial;
    return 0;
}