#pragma once
#include"Worker.h"

//ְ��֮Ա����
class Employee : public Worker
{
public:
	//���캯��
	Employee(int id,string name,int dept);
	//չʾ������Ϣ
	void showInfo();
	//���ظ�λ����
	string getDeptName();
};