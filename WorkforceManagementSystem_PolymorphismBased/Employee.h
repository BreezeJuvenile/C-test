#pragma once
#include"Worker.h"

//职工之员工类
class Employee : public Worker
{
public:
	//构造函数
	Employee(int id,string name,int dept);
	//展示个人信息
	void showInfo();
	//返回岗位名称
	string getDeptName();
};