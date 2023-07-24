#include <iostream>
using namespace std;
#include <string>
//#include <unistd.h>
#define MAX 1000

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void pauseAndClear()
{
    // mac 下实现暂停输出和清屏功能
    //cin.ignore();
    //cin.get();
    //system("clear");

    // windows 下的实现
     system("pause");
     system("cls");
}

void addPerson(AddressBooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        string phone;
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        string address;
        cout << "请输入家庭地址：" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++;

        cout << "添加成功！" << endl;

        pauseAndClear();
    }
}

void showPerson(AddressBooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }

    pauseAndClear();
}

int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs)
{
    cout << "请输入您要删除的联系人：" << endl;
    string name;
    cin >> name;

    int result = isExist(abs, name);
    if (result == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        for (int i = result; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功！" << endl;
    }

    pauseAndClear();
}

void findPerson(AddressBooks *abs)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;

    int result = isExist(abs, name);
    if (result == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        cout << "姓名：" << abs->personArray[result].m_Name << "\t";
        cout << "性别：" << (abs->personArray[result].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[result].m_Age << "\t";
        cout << "电话：" << abs->personArray[result].m_Phone << "\t";
        cout << "住址：" << abs->personArray[result].m_Addr << endl;
    }

    pauseAndClear();
}

void modifyPerson(AddressBooks *abs)
{
    cout << "请输入您要修改的联系人：" << endl;
    string name;
    cin >> name;

    int result = isExist(abs, name);
    if (result == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[result].m_Name = name;

        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[result].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[result].m_Age = age;

        string phone;
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        abs->personArray[result].m_Phone = phone;

        string address;
        cout << "请输入家庭地址：" << endl;
        cin >> address;
        abs->personArray[result].m_Addr = address;

        cout << "修改完成！" << endl;
    }

    pauseAndClear();
}

void clearPerson(AddressBooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空！" << endl;
    pauseAndClear();
}

void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

int main()
{
    AddressBooks abs;
    abs.m_Size = 0;

    int select = 0;
    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            clearPerson(&abs);
            break;
        case 0:
            cout << "欢迎下次使用！" << endl;
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}