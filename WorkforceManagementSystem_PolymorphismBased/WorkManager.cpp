#include"WorkManager.h"

WorkerManager::WorkerManager()
{
	//1���ļ�������ʱ�ĳ�ʼ��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ���� �ļ�������ʱ��ifs.is_open()���� false
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;

		//���ݽ��г�ʼ��
		//�ļ��ж�Ϊ��
		fileEmpty = true;
		//��¼ְ������
		int m_EmpNum = 0;
		//����ְ��ָ��
		Worker** m_EmpArray = NULL;
		//�ر��ļ�
		ifs.close();
		return;
	}
	//2���ļ����ڣ�������Ϊ��
	if (ifs.is_open())
	{
		//���ȶ�ȡ�ļ��е�һ���ַ�������ļ�Ϊ�գ�
		//���ļ���Ӧֻ����һ����β�����Դ��ж��ļ��Ƿ�Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//�ļ�Ϊ��
			//cout << "�ļ����ڵ����κ����ݣ�" << endl;

			//���ݽ��г�ʼ��
			//�ļ��ж�Ϊ��
			fileEmpty = true;
			//��¼ְ������
			int m_EmpNum = 0;
			//����ְ��ָ��
			Worker** m_EmpArray = NULL;
			//�ر��ļ�
			ifs.close();
			return;
		}
	}
	//3���ļ����ڣ�����¼����������ʱ�ĳ�ʼ��
	int num = this->getEmpSum();
	//cout << "����ְ��������Ϊ " << num << endl;
	this->m_EmpNum = num;
	//����������������ְ������ռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//������Ա����Ž�ȥ
	this->initEmployee();
}

void WorkerManager::showManu()
{
	cout << "*******************************************" << endl;
	cout << "*********** ��ӭʹ��ְ������ϵͳ��*********" << endl;
	cout << "************* 1������ְ����Ϣ *************" << endl;
	cout << "************* 2����ʾְ����Ϣ *************" << endl;
	cout << "************* 3��ɾ��ְ����Ϣ *************" << endl;
	cout << "************* 4���޸�ְ����Ϣ *************" << endl;
	cout << "************* 5������ְ����Ϣ *************" << endl;
	cout << "************* 6�����ձ������ *************" << endl;
	cout << "************* 7����������ĵ� *************" << endl;
	cout << "************* 0���˳�������� *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

//���ְ��
void WorkerManager::addEmp()
{
	cout << "��������Ҫ��ӵ�ְ��������" << endl;
	//��¼��������
	int newNum = 0, sign = 3;    //sign��ʾ����Ļ��������
	while (sign)
	{
		cin >> newNum;
		if (newNum > 0)
		{
			//���
			//��¼������������
			int newSize = this->m_EmpNum + newNum;
			//�����¿ռ��ų�����ָ�루��Ӵ��ְ����Ϣ��
			Worker** newSpace = new Worker * [newSize];
			if (this->m_EmpArray != NULL)
			{
				//���Ԫ��ſռ��Ѿ�����ְ�������Ȱ�����ְ����ӵ��¿ռ�
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//������Ҫ����ְ���������������ְ��
			for (int i = 0; i < newNum; i++)
			{
				//����ְ������
				int id = 0;   //ְ�����
				string name;   //ְ������
				int dSelect;   //ְ��ѡ��ĸ�λ

				cout << "������� " << i + 1 << " ������ְ����ţ�" << endl;
				cin >> id;
				cout << "������� " << i + 1 << " ������ְ��������" << endl;
				cin >> name;
				cout << "������� " << i + 1 << " ������ְ���ĸ�λ��" << endl;
				cout << "1����ͨԱ��" << endl
					<< "2������" << endl
					<< "3���ϰ�" << endl;
				cin >> dSelect;

				//����Switch��䴴����ͬ��λ��ְ�����������ʱָ��worker��
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					cout << "�����������" << endl;
					system("pause");
					system("cls");
					return;
				}
				//����ְ����ӵ��¿ռ�
				newSpace[this->m_EmpNum + i] = worker;
			}
			//��������ְ�������Ϣ�Լ�����
			//�ͷ�ԭ�пռ�
			delete[] this->m_EmpArray;
			//�¿ռ丳ֵ�����ְ����Ϣ�Ŀռ�
			this->m_EmpArray = newSpace;
			//����ְ������
			this->m_EmpNum = newSize;
			//�����ļ����
			fileEmpty = false;
			cout << "�ɹ���� " << newNum << " ����ְ����" << endl;
			//��Ϣ�������ļ�
			saveInfoToFile();

			break;     //��������ѭ��
		}
		else
		{
			cout << "��������!" << endl;
			sign--;
			if (sign == 0)
			{
				cout << "��Ǹ�����������������࣬���޷����룡" << endl;
			}
			else
			{
				cout << "����ʣ" << sign << "������Ļ��ᣬ�������������룺" << endl;
				continue;   //��������ѭ������������
			}
		}
	}
	//��ͣ�������û�����ʱ��
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::saveInfoToFile()
{
	//�����ļ�
	ofstream ofs;
	//���ļ�
	ofs.open(FILENAME, ios::out);
	//����Ϣд���ļ�
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		ofs << this->m_EmpArray[i]->Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Dept << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��¼����ְ������
int WorkerManager::getEmpSum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	return num;
}

//��ʼ��ְ��
void WorkerManager::initEmployee()
{
	//��ȡ���ݣ����������ְ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int idenx = 0;   //���ڱ�Ǵ��λ��

	//��ȡ����¼
	Worker* worker = NULL;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//���ݸ�λ��ͬȷ����ͬԱ��
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		//�����ְ������
		this->m_EmpArray[idenx] = worker;
		idenx++;
	}
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void WorkerManager::showEmployee()
{
	//�ж��ļ��Ƿ�Ϊ�ջ����
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->getEmpSum(); i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//��ͣ�������û��㹻����ʱ�䣬����-��֤����ļ��
	system("pause");
	system("cls");
}

//�ж�ĳְ���Ƿ���ڣ������򷵻�λ�ã������ڷ���-1
int WorkerManager::employeePos(int id)
{
	//δ��������ֱ�ӷ���-1
	int pos = -1;  //λ�ó�ʼ-1
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		if (id == this->m_EmpArray[i]->Id)
		{
			//�ҵ�ְ��λ��
			pos = i;
			break;
		}
	}
	return pos;
}

//�����ɾ��ְ��---����ǰ�Ƹ�����ɾ����
void WorkerManager::delEmployee()
{
	//�ж��ļ��Ƿ���ڻ��¼�Ƿ�Ϊ��
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�����Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		int id = 0;
		cout << "����������ɾ����ְ����Ӧ��ţ�";
		cin >> id;
		int index = this->employeePos(id);
		if (index != -1)
		{
			//ɾ��--����ǰ�ƣ�����ɾ��λ�ú�һ����ʼǰ��
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//ǰ��--���������ջὫi+1��λ��ǰ�ƣ�����Ϊ�������������i+1Ӧ<this->m_EMpNum
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			//����ɾ����ְ��������
			this->m_EmpNum--;
			//�����ļ��б����ְ��--����������д�����ļ�
			this->saveInfoToFile();
			//ɾ�����
			cout << "ɾ���ɹ���" << endl;

			//Bug ��ɾ�����һ����Ϣʱ��Ҫ���ļ����жϱ�Ϊtrue,
			//����ɾ�����һ��ְ����Ϣ��ʹ��Ϊ���ļ�ʱ��ʹ���������ܲ���ʾ�û���ʾ��Ͱ����������
			if (this->m_EmpNum == 0)
			{
				//�ļ����ж���Ϊ��
				this->fileEmpty = true;
			}
		}
		else
		{
			//δ�ҵ�
			cout << "������ְ������Լ������Ϣ,ɾ��ʧ�ܣ�" << endl;
		}
	}
	//��ͣ������
	system("pause");
	system("cls");
}

//�޸�ְ������
void WorkerManager::modifyEmployeeData()
{
	//�ж��ļ��Ƿ���ڻ��¼�Ƿ�Ϊ��
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�����Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		int id = 0;
		cout << "����������ɾ����ְ����Ӧ��ţ�";
		cin >> id;
		int index = this->employeePos(id);
		if (index != -1)
		{
			//������������ݵı���
			int newId = 0;
			string newName;
			int newSelectDeptId = 0;

			cout << "���Ϊ " << id << " ��ְ�����ҵ���" << endl<<endl;
			//չʾ��Ҫ�޸ĵ�ְ����Ϣ�������û��Ա��޸�
			cout << "Ϊ�������޸ģ����½�չʾ��ְ���������Ϣ��" << endl;
			this->m_EmpArray[index]->showInfo();

			//Ȼ���ͷ�ԭְ������
			delete this->m_EmpArray[index];

			//��ʱ����޸�����
			cout <<endl<< "�������µ�ְ����ţ�";
			cin >> newId;
			cout << "�������µ�ְ��������";
			cin >> newName;
			cout << "��������ְ�����ڸ�λ��ţ�" << endl;
			cout << "1����ͨԱ��" << endl
				 << "2������" << endl
				 << "3���ϰ�" << endl;
			cin >> newSelectDeptId;

			//����ѡ��Ĳ�ͬ��λ������ͬ��λ��ְ���ռ�
			//������ʱ���ְ���Ŀռ�
			Worker* worker = NULL;
			//��֧���ʵ����Ӧ�ؼ�����
			switch (newSelectDeptId)
			{
			case 1:
				worker = new Employee(newId, newName, newSelectDeptId);
				break;
			case 2:
				worker = new Manager(newId, newName, newSelectDeptId);
				break;
			case 3:
				worker = new Boss(newId, newName, newSelectDeptId);
				break;
			default:
				//�쳣�˳�����
				cout << "��ְ�����ű����������" << endl;
				system("pause");
				system("cls");
				return;
			}
			//���������ж�Ӧ������
			this->m_EmpArray[index] = worker;

			cout << "�޸ĳɹ���" << endl;
			//����д���޸ĺ��ְ�������е����ݲ����浽�ļ���
			this->saveInfoToFile();
		}
		else
		{
			//������
			cout << "��ְ����Ų�����,�޸�ʧ�ܣ�" << endl;
		}
	}
	//���û���ʱ�䲢��������߽���ļ����
	system("pause");
	system("cls");
}

//����ְ����Ϣ���ݱ��/������
void WorkerManager::findEmployee()
{
	//�ж��ļ��Ƿ���ڻ��¼�Ƿ�Ϊ��
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�����Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		int select = 0;
		cout << "��ѡ�����Ĳ��ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl
			<< "2����ְ����������" << endl;
		cin >> select;

		if (select == 1)   //�����
		{
			int id = 0;
			cout << "������������ҵ�ְ����ţ�";
			cin >> id;
			//�жϸ�ְ������Ƿ����
			int ret = this->employeePos(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���" << endl;
				cout << "�����������ҵı��Ϊ " << id << " ��ְ���������Ϣ��" << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "���޴��ˣ�����ʧ�ܣ�" << endl;
			}
		}
		if (select == 2)    //������
		{
			string name;
			cout << "�����������ҵ�ְ��������" << endl;
			cin >> name;
			//�ж��Ƿ���ڸ�������ְ��
			bool is_ExitFindName = false;
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					//���ҵ����Ϊtrue
					is_ExitFindName = true;
					//��ӡ�ҵ���ְ����Ϣ
					cout << "���ҳɹ���"<< "����Ϊ " << name << " ��ְ����Ϣ���£�" << endl;
					
					cout << "   ";   //��������������û��۸�

					//���Ӵ�ӡ��Ϣ��ɫ����ǿ�Ӿ�Ч��
					HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(outHandle, 0x06);
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
					SetConsoleTextAttribute(outHandle, 0x07);
				}
			}
			if (is_ExitFindName == false)
			{
				cout << "δ�ҵ���Ӧ������ְ��������ʧ�ܣ�" << endl;
			}
		}
	}
	//��ͣ������
	system("pause");
	system("cls");
}

//ְ������(ѡ������ʵ��)
void WorkerManager::employeeSort()
{
	//�ж��ļ��Ƿ���ڻ��ļ��Ƿ�Ϊ��
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�����ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��ѡ������Ҫ������ʽ��" << endl;
	cout << "1���������������" << endl
		 << "2������Ž�������" << endl;

	int select = 0, sign = 3;
	//�����쳣����
	while (sign)
	{
		cin >> select;
		if ((select != 1) && (select != 2))
		{
			cout << "����ѡ����ڣ�" << endl;
			sign--;
			if (sign == 0)
			{
				cout << "�ܱ�Ǹ�����������������࣬���޷�����ѡ��" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "������" << sign << "�λ���ѡ��" << "���������룺";
			continue;
		}
		break;
	}
	//ѡ������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//����Ĭ����Сֵ�����ֵ
		int minOrMax = i;
		for (int j = i + 1; j < this->m_EmpNum; j++)
		{
			if (select == 1)   //����
			{
				//��������ְ����� С�� Ĭ����С��ţ�
				//�򽫺�һ��ְ��λ����ΪĬ�ϱ����С��λ��
				if (this->m_EmpArray[minOrMax]->Id > this->m_EmpArray[j]->Id)
				{
					minOrMax = j;
				}
			}
			else    //����
			{
				//������ͬ��
				if (this->m_EmpArray[minOrMax]->Id  < this->m_EmpArray[j]->Id)
				{
					minOrMax = j;
				}
			}
			
		}
		//�жϵ�i�ֱȽϺ�ԭ��С���λ���Ƿ�仯�����仯�򽻻���Ӧְ����Ϣ
		if (i != minOrMax)
		{
			//������Ϣ
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax] = temp;
		}
	}
	//�������
	cout << "����ɹ��������ְ����Ϣ���£�" << endl;
	//��д������������ְ����Ϣ���ļ���
	this->saveInfoToFile();
	//��ʾ������ְ����Ϣ
	this->showEmployee();   //������ʾ��Ϣ�������Ѿ�������ͣ���������ܣ����Դ�ʱ�����Լ���
}

//����ļ�����
void WorkerManager::clearFileData()
{
	//�ж��ļ��Ƿ���ڻ��Ƿ�Ϊ��
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ����ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "��ȷ��Ҫ�����" << endl;
		cout << "1��ȷ����գ�" << endl << "2��������ˣ�����" << endl;
		int select = 0;
		cin >> select;

		//���
		if (select == 1)
		{
			//����ļ�----ɾ���ļ������´���һ�����ļ�
			ofstream ofs(FILENAME, ios::trunc);
			//�ͷŴ��ְ�������пռ�
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					//�ͷŲ��ÿո�������Ԫ�ز��ÿ�
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
						this->m_EmpArray[i] = NULL;
					}
				}
				//ְ������ռ��ͷŲ��ÿ�
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				//ְ��������Ϊ0
				this->m_EmpNum = 0;
				//�ļ���պ��ж��ļ�Ϊ�յ�������Ϊtrue
				this->fileEmpty = true;

				cout << "��ճɹ���" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{
	//�����ڴ��ֶ������ֶ��ͷ�
	if (this->m_EmpArray != NULL)
	{
		//��ÿһ��Ԫ�ؾ��ͷ�
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//�ͷ�
				delete this->m_EmpArray[i];
			}
		}
		//�ڲ�Ԫ���ͷ���Ϻ��ٰ������ռ���ͷţ������ÿ�
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}