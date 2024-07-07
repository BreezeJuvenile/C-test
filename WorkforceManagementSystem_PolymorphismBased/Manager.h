#pragma once
#include"Worker.h"

//职工之经理类
class Manager : public Worker
{
public:
	//构造函数
	Manager(int id, string name, int dept);
	//展示个人信息
	void showInfo();
	//返回岗位名称
	string getDeptName();
};