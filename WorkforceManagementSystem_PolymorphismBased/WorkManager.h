#pragma once
#include<iostream>
#include<cstdlib>
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
#include<windows.h>

#define FILENAME "EmployeeInfoFile.txt"

using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//�˵�չʾ
	void showManu();

	/*
	                         ���ְ������
	  ���ݶ�̬�����ԣ��������������������Ż���ָ���Լ�Ӵ���¼�ְ����
	  ����m_EmpNum��¼����ְ�����������ʱ����newNum��¼��Ҫ������������
	  �����¿ռ������������ְ��������Switch���ʵ���û�ѡ�����ְ���Ĳ��Ÿ�λ��
	  �����ͷ�ԭ��ְ������ռ䣬���¿ռ丳��ְ�������Լ��������ְ����������ԭְ������
	*/

	//��¼ְ������
	int m_EmpNum;

	//����ְ��ָ��
	Worker** m_EmpArray;
	
	//���ְ����Ϣ��������
	void addEmp();

	/*
	  ��Ӳ�ְ����Ϣ��Ϊ���ܷ���鿴�����ñ��棬���ǽ�����һ���ļ���¼�ͱ���ְ����Ϣ
	*/

	//�����ļ�
	void saveInfoToFile();

	/*
	  д���ļ��󣬵�ÿ�δ򿪳��򶼻Ὣ���ݳ�ʼ���������ݱ���գ��������޷�����
	  �鿴����ְ����Ϣ�����У����ļ�ʱ�������������
	  1����һ�μ�¼���ݣ��ļ���δ����
	  2���Ѿ������ļ��������ļ��е����ݱ������
	  3���ļ��Ѿ����ڣ��ұ�����������ӵ�ְ����Ϣ������
	*/

	//�ж��ļ��Ƿ�Ϊ��
	bool fileEmpty;

	//��¼����ְ������
	int getEmpSum();

	//��ʼ��ְ��
	void initEmployee();

	//��ʾְ��
	void showEmployee();

	/*
	  �����ɾ��ְ����Ϣ�������ж��ļ��Ƿ�����Լ��ļ��Ƿ�Ϊ�գ�
	  ���ж��ļ����Ƿ���ڸ�ְ����ţ���������ִ��ɾ������
	  ����Ҫɾ�����ݺ�����������ǰ�ƣ�������ɾ���ݲ�ʹְ������-1��
	  ��������д�벢����ɾ��ְ��������ݣ�
	  ʹ�����մﵽ�߼��ϵ�ְ������ɾ��������
	*/

	//�ж�ĳְ���Ƿ���ڣ������򷵻�λ�ã������ڷ���-1
	int employeePos(int id);

	//�����ɾ��ְ��
	void delEmployee();

	//�޸�ְ������
	void modifyEmployeeData();

	//����ְ����Ϣ���ݱ��/������
	void findEmployee();

	//ְ������
	void employeeSort();

	//����ļ�����
	void clearFileData();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~WorkerManager();
};