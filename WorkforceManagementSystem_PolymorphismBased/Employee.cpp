#include"Employee.h"

//构造函数
Employee::Employee(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//展示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t部门职责：完成经理交给的任务 " << endl;
}
//返回岗位名称
string Employee::getDeptName()
{
	return string("员工");
}