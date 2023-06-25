#include <iostream>
using namespace std;

// 计算自然数之和(计算 1+2+3+....+n 的和。)
int main6()
{
    int n, sum = 0;

    cout << "输入一个正整数: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "Sum = " << sum;
    return 0;
}