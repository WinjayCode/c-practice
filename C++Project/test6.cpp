#include <iostream>
using namespace std;

// ������Ȼ��֮��(���� 1+2+3+....+n �ĺ͡�)
int main6()
{
    int n, sum = 0;

    cout << "����һ��������: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "Sum = " << sum;
    return 0;
}