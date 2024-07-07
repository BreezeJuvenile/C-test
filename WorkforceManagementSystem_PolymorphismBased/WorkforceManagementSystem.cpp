#include<iostream>
#include"WorkManager.h"
using namespace std;

int main()
{
	WorkerManager wm;
	//showTest();
	while (1)
	{
		wm.showManu();
		int choice;
		cout << "请输入您的选择：";
		cin >> choice;

		switch (choice)
		{
			case 1:       //增加职工信息
				wm.addEmp();
				break;
			case 2:       //显示职工信息
				wm.showEmployee();
				break;
			case 3:       //删除职工信息
				wm.delEmployee();
				break;
			case 4:       //修改职工信息
				wm.modifyEmployeeData();
				break;
			case 5:       //查找职工信息
				wm.findEmployee();
				break;
			case 6:       //按照编号排序
				wm.employeeSort();
				break;
			case 7:       //清空所有文档
				wm.clearFileData();
				break;
			case 0:       //退出管理程序
				wm.exitSystem();
				break;
			default:
				cout << "输入有误,请重新输入!" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}


////展示信息测试
//void showTest()
//{
//	//员工
//	Worker* worker1 = NULL;
//	worker1 = new Employee(1, "张三", 1);
//	//输出
//	worker1->showInfo();
//	delete worker1;
//
//	//经理
//	Worker* worker2 = NULL;
//	worker2 = new Manager(2, "李四", 2);
//	//输出
//	worker2->showInfo();
//	delete worker2;
//
//	//老板
//	Worker* worker3 = NULL;
//	worker3 = new Employee(3, "王五", 3);
//	//输出
//	worker3->showInfo();
//	delete worker3;
//}
//
////判断存在的测试
//void isExitPos_Test(WorkerManager wm)
//{
//	int ret = wm.employeePos(1);
//	if (ret != -1)
//	{
//		cout << "职工存在！" << endl;
//	}
//	else
//	{
//		cout << "职工不存在！" << endl;
//	}
//}