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
		cout << "����������ѡ��";
		cin >> choice;

		switch (choice)
		{
			case 1:       //����ְ����Ϣ
				wm.addEmp();
				break;
			case 2:       //��ʾְ����Ϣ
				wm.showEmployee();
				break;
			case 3:       //ɾ��ְ����Ϣ
				wm.delEmployee();
				break;
			case 4:       //�޸�ְ����Ϣ
				wm.modifyEmployeeData();
				break;
			case 5:       //����ְ����Ϣ
				wm.findEmployee();
				break;
			case 6:       //���ձ������
				wm.employeeSort();
				break;
			case 7:       //��������ĵ�
				wm.clearFileData();
				break;
			case 0:       //�˳��������
				wm.exitSystem();
				break;
			default:
				cout << "��������,����������!" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}


////չʾ��Ϣ����
//void showTest()
//{
//	//Ա��
//	Worker* worker1 = NULL;
//	worker1 = new Employee(1, "����", 1);
//	//���
//	worker1->showInfo();
//	delete worker1;
//
//	//����
//	Worker* worker2 = NULL;
//	worker2 = new Manager(2, "����", 2);
//	//���
//	worker2->showInfo();
//	delete worker2;
//
//	//�ϰ�
//	Worker* worker3 = NULL;
//	worker3 = new Employee(3, "����", 3);
//	//���
//	worker3->showInfo();
//	delete worker3;
//}
//
////�жϴ��ڵĲ���
//void isExitPos_Test(WorkerManager wm)
//{
//	int ret = wm.employeePos(1);
//	if (ret != -1)
//	{
//		cout << "ְ�����ڣ�" << endl;
//	}
//	else
//	{
//		cout << "ְ�������ڣ�" << endl;
//	}
//}