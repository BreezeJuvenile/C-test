#pragma once
#include"Worker.h"

//ְ��֮�ϰ���
class Boss : public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dept);
	//չʾ������Ϣ
	void showInfo();
	//���ظ�λ����
	string getDeptName();
};