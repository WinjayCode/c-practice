#include <iostream>
using namespace std;

static void method1()
{
    char op;
    float num1, num2;

    cout << "�����������+��-��*��/ : ";
    cin >> op;

    cout << "����������: ";
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
            cout << "error���ܳ�����";
            break;
        }
        else
        {
            cout << num1 / num2;
            break;
        }

    default:
        // ������������ +, -, * �� /, ��ʾ������Ϣ
        cout << "Error!  ��������ȷ�������";
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
        cout << "���󣺳�������Ϊ�㣡" << endl;
        return 0;
    }
}

static void method2()
{
    double num1, num2;
    char op;

    cout << "�������һ�����֣�";
    cin >> num1;

    cout << "�������������+��-��*��/����";
    cin >> op;

    cout << "������ڶ������֣�";
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
        cout << "������Ч���������" << endl;
        break;
    }

    cout << "�����" << result << endl;
}

// ʵ��һ���򵥵ļ�����
int main12()
{
    method1();
    //method2();

    return 0;
}