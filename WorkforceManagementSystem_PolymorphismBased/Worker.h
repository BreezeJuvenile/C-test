#pragma once
#include<iostream>

using namespace std;

//ְ��������
class Worker
{
public:
	virtual void showInfo() = 0;

	//��ȡ���Ÿ�λ
	virtual string getDeptName() = 0;

	int Id;   //���
	string m_Name;   //����
	int m_Dept;   //���ű�� 1-Ա�� 2-���� 3-�ϰ�
};