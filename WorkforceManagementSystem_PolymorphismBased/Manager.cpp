#include"Manager.h"

//构造函数
Manager::Manager(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//展示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t部门职责：完成老板交给的任务，并下发任务给员工 " << endl;
}
//返回岗位名称
string Manager::getDeptName()
{
	return string("经理");
}