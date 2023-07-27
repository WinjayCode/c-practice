#include"Boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartmentId = dId;
}

void Boss::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工名称： " << this->m_Name
		<< " \t岗位： " << this->getDepartmentName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDepartmentName()
{
	return "老板";
}