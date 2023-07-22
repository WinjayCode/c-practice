#include <iostream>
using namespace std;

static void method1()
{
    char op;
    float num1, num2;

    cout << "输入运算符：+、-、*、/ : ";
    cin >> op;

    cout << "输入两个数: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << num1 + num2;
        break;

    case '-':
        cout << num1 - num2;
        break;

    case '*':
        cout << num1 * num2;
        break;

    case '/':
        if (num2 == 0)
        {
            cout << "error不能除以零";
            break;
        }
        else
        {
            cout << num1 / num2;
            break;
        }

    default:
        // 如果运算符不是 +, -, * 或 /, 提示错误信息
        cout << "Error!  请输入正确运算符。";
        break;
    }
}



double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    }
    else {
        cout << "错误：除数不能为零！" << endl;
        return 0;
    }
}

static void method2()
{
    double num1, num2;
    char op;

    cout << "请输入第一个数字：";
    cin >> num1;

    cout << "请输入运算符（+、-、*、/）：";
    cin >> op;

    cout << "请输入第二个数字：";
    cin >> num2;

    double result;

    switch (op) {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = subtract(num1, num2);
        break;
    case '*':
        result = multiply(num1, num2);
        break;
    case '/':
        result = divide(num1, num2);
        break;
    default:
        cout << "错误：无效的运算符！" << endl;
        break;
    }

    cout << "结果：" << result << endl;
}

// 实现一个简单的计算器
int main12()
{
    method1();
    //method2();

    return 0;
}