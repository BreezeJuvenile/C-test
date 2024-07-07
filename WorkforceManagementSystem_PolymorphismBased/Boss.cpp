#include"Boss.h"

//构造函数
Boss::Boss(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//展示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t部门职责：管理公司所有事务 " << endl;
}
//返回岗位名称
string Boss::getDeptName()
{
	return string("老板");
}