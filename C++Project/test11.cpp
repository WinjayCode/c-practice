#include <iostream>
using namespace std;

static void method1()
{
    int n1, n2, max;

    cout << "输入两个数: ";
    cin >> n1 >> n2;

    // 获取最大的数
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

// 最小公倍数=(n1 * n2) / 最大公约数
static void method2()
{
    int n1, n2, hcf, temp, lcm;

    cout << "输入两个数: ";
    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;

    // 求出两数最大公约数
    while (hcf != temp)
    {
        if (hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    // 公式
    lcm = (n1 * n2) / hcf;

    cout << "LCM = " << lcm;
}

// 求两数最小公倍数
int main11()
{
    method1();
    //method2();

    return 0;
}