#include"Employee.h"

//���캯��
Employee::Employee(int id, string name, int dept)
{
	this->Id = id;
	this->m_Name = name;
	this->m_Dept = dept;
}
//չʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ����ɾ����������� " << endl;
}
//���ظ�λ����
string Employee::getDeptName()
{
	return string("Ա��");
}