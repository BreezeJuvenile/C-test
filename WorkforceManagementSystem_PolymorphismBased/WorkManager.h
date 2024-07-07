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
	//构造函数
	WorkerManager();

	//菜单展示
	void showManu();

	/*
	                         添加职工人数
	  根据多态的特性，创建抽象类类型数组存放基类指针以间接存放新加职工，
	  并用m_EmpNum记录已有职工人数，添加时利用newNum记录需要新增的人数，
	  创建新空间存放新增后的总职工，并用Switch语句实现用户选择添加职工的部门岗位，
	  接着释放原本职工数组空间，将新空间赋予职工数组以及新增后的职工人数赋予原职工人数
	*/

	//记录职工人数
	int m_EmpNum;

	//创建职工指针
	Worker** m_EmpArray;
	
	//添加职工信息（批量）
	void addEmp();

	/*
	  添加并职工信息后，为了能方便查看和永久保存，我们将创建一个文件记录和保存职工信息
	*/

	//保存文件
	void saveInfoToFile();

	/*
	  写入文件后，但每次打开程序都会将数据初始化导致数据被清空，以至于无法后期
	  查看已有职工信息。其中，读文件时，有三种情况：
	  1、第一次记录数据，文件还未创建
	  2、已经存在文件，但是文件中的数据被清空了
	  3、文件已经存在，且保存了所有添加的职工信息的数据
	*/

	//判断文件是否为空
	bool fileEmpty;

	//记录已有职工人数
	int getEmpSum();

	//初始化职工
	void initEmployee();

	//显示职工
	void showEmployee();

	/*
	  按编号删除职工信息，首先判断文件是否存在以及文件是否为空，
	  再判断文件中是否存在该职工编号，若存在则执行删除操作
	  对需要删除数据后面所有数据前移，覆盖需删数据并使职工总数-1，
	  接着重新写入并保存删除职工后的数据，
	  使得最终达到逻辑上的职工数据删除操作。
	*/

	//判断某职工是否存在，存在则返回位置，不存在返回-1
	int employeePos(int id);

	//按编号删除职工
	void delEmployee();

	//修改职工数据
	void modifyEmployeeData();

	//查找职工信息（据编号/姓名）
	void findEmployee();

	//职工排序
	void employeeSort();

	//清空文件数据
	void clearFileData();

	//退出系统
	void exitSystem();

	//析构函数
	~WorkerManager();
};