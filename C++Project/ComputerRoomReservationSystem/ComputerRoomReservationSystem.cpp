#include<iostream>
using namespace std;
#include"GlobalFile.h"
#include"Identity.h"
#include<fstream>

// 登录 参数1 操作文件名  参数2 操作身份类型
void LoginIn(string fileName, int type)
{
	// 父类指针，用于指向子类对象
	Identity* person = NULL;

	// 读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// 文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 学生身份验证
	if (type == 1)
	{

	}
	// 教师身份验证
	else if (type == 2)
	{

	}
	// 管理员身份验证
	else if (type == 3)
	{

	}

	cout << "验证登录失败！" << endl;

	pauseAndClear();
}

void exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void pauseAndClear()
{
	// mac 下实现暂停输出和清屏功能
	// cin.ignore();
	// cin.get();
	// system("clear");

	// windows 下的实现
	system("pause");
	system("cls");
}

int main()
{
	// only for windows system
	system("chcp 65001");

	int select = 0;

	while (true)
	{
		cout << "================= 欢迎使用机房预约系统 =================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ----------------------\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1.学生代表      |\n";
		cout << "\t\t|      2.老    师      |\n";
		cout << "\t\t|      3.管 理 员      |\n";
		cout << "\t\t|      0.退    出      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t ----------------------\n";
		cout << "输入您的选择：" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			exitSystem();
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			pauseAndClear();
			break;
		}
	}

	return 0;
}