#include"Administrator.h"

// 默认构造
Administrator::Administrator()
{

}

// 有参构造（管理员姓名、密码）
Administrator::Administrator(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	initVector();

	// 获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vComputerRoom.push_back(c);
	}
	//cout << "当前机房数量为：" << vComputerRoom.size() << endl;
	ifs.close();
}

// 选择菜单
void Administrator::operMenu()
{
	cout << "欢迎管理员：" << m_Name << "登录！" << endl;
	cout << "\t\t ----------------------\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.添加账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.查看账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.查看机房      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4.清空预约      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.注销登录      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t ----------------------\n";
	cout << "请选择您的操作：" << endl;
}

// 添加账号
void Administrator::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTip = "职工号重复，请重新输入！";
	}

	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool result = checkRepeat(id, select);
		if (result)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	ofs.close();

	// 更新容器数据
	initVector();

	pauseAndClear();
}

void printStudent(Student &s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

// 查看账号
void Administrator::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStudent.begin(), vStudent.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
	}

	pauseAndClear();
}

// 查看机房信息
void Administrator::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vComputerRoom.begin(); it != vComputerRoom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	pauseAndClear();
}

// 清空预约记录
void Administrator::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	pauseAndClear();
}

// 初始化容器
void Administrator::initVector()
{
	vStudent.clear();
	vTeacher.clear();

	// 读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStudent.push_back(s);
	}
	//cout << "当前学生数量为：" << vStudent.size() << endl;
	ifs.close();

	// 读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTeacher.push_back(t);
	}
	//cout << "当前老师数量为：" << vTeacher.size() << endl;
	ifs.close();
}

// 检测重复
bool Administrator::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}