#include"Manager.h"

//���캯��
Manager::Manager(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//չʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ������ϰ彻�������񣬲��·������Ա�� " << endl;
}
//���ظ�λ����
string Manager::getDeptName()
{
	return string("����");
}