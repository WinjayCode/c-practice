#include"Employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartmentId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工名称： " << this->m_Name
		<< " \t岗位： " << this->getDepartmentName()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDepartmentName()
{
	return "员工";
}