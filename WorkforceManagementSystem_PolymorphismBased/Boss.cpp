#include"Boss.h"

//���캯��
Boss::Boss(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//չʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ�𣺹���˾�������� " << endl;
}
//���ظ�λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}