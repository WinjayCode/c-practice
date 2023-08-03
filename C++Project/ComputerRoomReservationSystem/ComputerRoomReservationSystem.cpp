#include<iostream>
using namespace std;
#include"GlobalFile.h"
#include"Identity.h"
#include<fstream>
#include"Student.h"
#include"Administrator.h"
#include"Teacher.h"
#include"Util.h"

static void exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//static void pauseAndClear()
//{
//	// mac 下实现暂停输出和清屏功能
//	// cin.ignore();
//	// cin.get();
//	// system("clear");
//
//	// windows 下的实现
//	system("pause");
//	system("cls");
//}

// 进入管理员子菜单界面
void administratorMenu(Identity* administrator)
{
	while (true)
	{
		// 管理员菜单
		administrator->operMenu();

		// 将父类指针转为子类指针，调用子类里其他接口
		Administrator* ad = (Administrator*)administrator;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			ad->addPerson();
		}
		else if (select == 2)
		{
			ad->showPerson();
		}
		else if (select == 3)
		{
			ad->showComputer();
		}
		else if (select == 4)
		{
			ad->cleanFile();
		}
		else if (select == 0)
		{
			delete ad; // 销毁堆区对象
			cout << "注销成功！" << endl;
			pauseAndClear();
			return;
		}
		else
		{
			cout << "输入有误，请重新选择！" << endl;
			pauseAndClear();
		}
	}
}

// 进入学生菜单
void studentMenu(Identity* student)
{
	while (true)
	{
		// 学生菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else if (select == 0)
		{
			delete stu; // 销毁堆区对象
			cout << "注销成功！" << endl;
			pauseAndClear();
			return;
		}
		else
		{
			cout << "输入有误，请重新选择！" << endl;
			pauseAndClear();
		}
	}
}

// 进入教师菜单
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		// 教师菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else if (select == 0)
		{
			delete tea; // 销毁堆区对象
			cout << "注销成功！" << endl;
			pauseAndClear();
			return;
		}
		else
		{
			cout << "输入有误，请重新选择！" << endl;
			pauseAndClear();
		}
	}
}

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
		int fId; // 从文件中读取的id号
		string fName; // 从文件中读取的姓名
		string fPwd; // 从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				pauseAndClear();
				person = new Student(id, name, pwd);
				// 进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	// 教师身份验证
	else if (type == 2)
	{
		int fId; // 从文件中读取的id号
		string fName; // 从文件中读取的姓名
		string fPwd; // 从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				pauseAndClear();
				person = new Teacher(id, name, pwd);
				// 进入教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	// 管理员身份验证
	else if (type == 3)
	{
		string fName; // 从文件中读取的姓名
		string fPwd; // 从文件中读取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				pauseAndClear();
				person = new Administrator(name, pwd);
				// 进入管理员身份的子菜单
				administratorMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	pauseAndClear();
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
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2.老    师      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3.管 理 员      |\n";
		cout << "\t\t|                      |\n";
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