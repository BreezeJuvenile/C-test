#pragma once
#include<iostream>

using namespace std;

//职工抽象类
class Worker
{
public:
	virtual void showInfo() = 0;

	//获取部门岗位
	virtual string getDeptName() = 0;

	int Id;   //编号
	string m_Name;   //姓名
	int m_Dept;   //部门编号 1-员工 2-经理 3-老板
};