#include"Manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartmentId = dId;
}

void Manager::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工名称： " << this->m_Name
		<< " \t岗位： " << this->getDepartmentName()
		<< " \t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDepartmentName()
{
	return "经理";
}