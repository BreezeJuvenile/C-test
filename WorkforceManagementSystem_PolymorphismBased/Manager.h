#pragma once
#include"Worker.h"

//ְ��֮������
class Manager : public Worker
{
public:
	//���캯��
	Manager(int id, string name, int dept);
	//չʾ������Ϣ
	void showInfo();
	//���ظ�λ����
	string getDeptName();
};