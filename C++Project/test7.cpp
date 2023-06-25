#include <iostream>
using namespace std;

// 判断闰年
int main7()
{
    int year;

    cout << "输入年份: ";
    cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            // // 这里如果被 400 整除是闰年
            if (year % 400 == 0)
                cout << year << " 是闰年";
            else
                cout << year << " 不是闰年";
        }
        else
            cout << year << " 是闰年";
    }
    else
        cout << year << " 不是闰年";

    return 0;
}