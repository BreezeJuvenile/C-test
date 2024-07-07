#pragma once
#include"Worker.h"

//职工之老板类
class Boss : public Worker
{
public:
	//构造函数
	Boss(int id, string name, int dept);
	//展示个人信息
	void showInfo();
	//返回岗位名称
	string getDeptName();
};