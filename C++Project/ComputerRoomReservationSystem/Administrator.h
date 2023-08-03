#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"GlobalFile.h"
#include"Util.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include"ComputerRoom.h"

class Administrator :public Identity
{
public:
	// 默认构造
	Administrator();

	// 有参构造（管理员姓名、密码）
	Administrator(string name, string pwd);

	// 选择菜单
	virtual void operMenu();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 清空预约记录
	void cleanFile();

	// 初始化容器
	void initVector();

	// 检测重复
	bool checkRepeat(int id, int type);

	// 学生容器
	vector<Student> vStudent;

	// 教师容器
	vector<Teacher> vTeacher;

	// 机房容器
	vector<ComputerRoom> vComputerRoom;
};