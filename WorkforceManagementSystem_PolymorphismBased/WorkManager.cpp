#include"WorkManager.h"

WorkerManager::WorkerManager()
{
	//1、文件不存在时的初始化
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//判断文件是否存在 文件不存在时，ifs.is_open()返回 false
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		//数据进行初始化
		//文件判断为空
		fileEmpty = true;
		//记录职工人数
		int m_EmpNum = 0;
		//创建职工指针
		Worker** m_EmpArray = NULL;
		//关闭文件
		ifs.close();
		return;
	}
	//2、文件存在，但数据为空
	if (ifs.is_open())
	{
		//首先读取文件中的一个字符，如果文件为空，
		//则文件中应只存在一个结尾符，以此判断文件是否为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//文件为空
			//cout << "文件存在但无任何数据！" << endl;

			//数据进行初始化
			//文件判断为空
			fileEmpty = true;
			//记录职工人数
			int m_EmpNum = 0;
			//创建职工指针
			Worker** m_EmpArray = NULL;
			//关闭文件
			ifs.close();
			return;
		}
	}
	//3、文件存在，并记录了所有数据时的初始化
	int num = this->getEmpSum();
	//cout << "现有职工总人数为 " << num << endl;
	this->m_EmpNum = num;
	//根据现有人数开辟职工数组空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将已有员工存放进去
	this->initEmployee();
}

void WorkerManager::showManu()
{
	cout << "*******************************************" << endl;
	cout << "*********** 欢迎使用职工管理系统！*********" << endl;
	cout << "************* 1、增加职工信息 *************" << endl;
	cout << "************* 2、显示职工信息 *************" << endl;
	cout << "************* 3、删除职工信息 *************" << endl;
	cout << "************* 4、修改职工信息 *************" << endl;
	cout << "************* 5、查找职工信息 *************" << endl;
	cout << "************* 6、按照编号排序 *************" << endl;
	cout << "************* 7、清空所有文档 *************" << endl;
	cout << "************* 0、退出管理程序 *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

//添加职工
void WorkerManager::addEmp()
{
	cout << "请输入您要添加的职工人数：" << endl;
	//记录新增人数
	int newNum = 0, sign = 3;    //sign表示输入的机会仅三次
	while (sign)
	{
		cin >> newNum;
		if (newNum > 0)
		{
			//添加
			//记录新增后总人数
			int newSize = this->m_EmpNum + newNum;
			//开辟新空间存放抽象类指针（间接存放职工信息）
			Worker** newSpace = new Worker * [newSize];
			if (this->m_EmpArray != NULL)
			{
				//如果元存放空间已经存在职工，则先把已有职工添加到新空间
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//根据需要新添职工数量批量添加新职工
			for (int i = 0; i < newNum; i++)
			{
				//新添职工属性
				int id = 0;   //职工编号
				string name;   //职工姓名
				int dSelect;   //职工选择的岗位

				cout << "请输入第 " << i + 1 << " 个新添职工编号：" << endl;
				cin >> id;
				cout << "请输入第 " << i + 1 << " 个新添职工姓名：" << endl;
				cin >> name;
				cout << "请输入第 " << i + 1 << " 个新添职工的岗位：" << endl;
				cout << "1、普通员工" << endl
					<< "2、经理" << endl
					<< "3、老板" << endl;
				cin >> dSelect;

				//利用Switch语句创建不同岗位的职工并存放至临时指针worker中
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
					cout << "编号输入有误" << endl;
					system("pause");
					system("cls");
					return;
				}
				//将新职工添加到新空间
				newSpace[this->m_EmpNum + i] = worker;
			}
			//更新已有职工存放信息以及数量
			//释放原有空间
			delete[] this->m_EmpArray;
			//新空间赋值给存放职工信息的空间
			this->m_EmpArray = newSpace;
			//更新职工数量
			this->m_EmpNum = newSize;
			//更新文件情况
			fileEmpty = false;
			cout << "成功添加 " << newNum << " 名新职工！" << endl;
			//信息保存至文件
			saveInfoToFile();

			break;     //跳出输入循环
		}
		else
		{
			cout << "输入有误!" << endl;
			sign--;
			if (sign == 0)
			{
				cout << "抱歉，您输入错误次数过多，已无法输入！" << endl;
			}
			else
			{
				cout << "您还剩" << sign << "次输入的机会，请认真重新输入：" << endl;
				continue;   //跳出本次循环，重新输入
			}
		}
	}
	//暂停，给予用户留意时间
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::saveInfoToFile()
{
	//创建文件
	ofstream ofs;
	//打开文件
	ofs.open(FILENAME, ios::out);
	//将信息写入文件
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		ofs << this->m_EmpArray[i]->Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Dept << endl;
	}
	//关闭文件
	ofs.close();
}

//记录已有职工人数
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

//初始化职工
void WorkerManager::initEmployee()
{
	//读取数据，添加数据至职工数组
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int idenx = 0;   //用于标记存放位置

	//读取并记录
	Worker* worker = NULL;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//根据岗位不同确定不同员工
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
		//存放至职工数组
		this->m_EmpArray[idenx] = worker;
		idenx++;
	}
	//关闭文件
	ifs.close();
}

//显示职工
void WorkerManager::showEmployee()
{
	//判断文件是否为空或存在
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->getEmpSum(); i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//暂停，给予用户足够留意时间，清屏-保证界面的简洁
	system("pause");
	system("cls");
}

//判断某职工是否存在，存在则返回位置，不存在返回-1
int WorkerManager::employeePos(int id)
{
	//未遍历到则直接返回-1
	int pos = -1;  //位置初始-1
	for (int i = 0; i < this->m_EmpNum; ++i)
	{
		if (id == this->m_EmpArray[i]->Id)
		{
			//找到职工位置
			pos = i;
			break;
		}
	}
	return pos;
}

//按编号删除职工---数据前移覆盖需删数据
void WorkerManager::delEmployee()
{
	//判断文件是否存在或记录是否为空
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件数据为空，无法删除！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入您想删除的职工对应编号：";
		cin >> id;
		int index = this->employeePos(id);
		if (index != -1)
		{
			//删除--数据前移，从需删除位置后一个开始前移
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//前移--由于是最终会将i+1的位置前移，所以为避免数组溢出，i+1应<this->m_EMpNum
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			//更新删除后职工的总数
			this->m_EmpNum--;
			//更新文件中保存的职工--对数据重新写入新文件
			this->saveInfoToFile();
			//删除完毕
			cout << "删除成功！" << endl;

			//Bug 当删除最后一个信息时，要将文件空判断变为true,
			//避免删除最后一条职工信息后使变为空文件时，使用其他功能不显示用户提示语就按任意键继续
			if (this->m_EmpNum == 0)
			{
				//文件空判断置为真
				this->fileEmpty = true;
			}
		}
		else
		{
			//未找到
			cout << "不含该职工编号以及相关信息,删除失败！" << endl;
		}
	}
	//暂停和清屏
	system("pause");
	system("cls");
}

//修改职工数据
void WorkerManager::modifyEmployeeData()
{
	//判断文件是否存在或记录是否为空
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件数据为空，无法删除！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入您想删除的职工对应编号：";
		cin >> id;
		int index = this->employeePos(id);
		if (index != -1)
		{
			//创建存放新数据的变量
			int newId = 0;
			string newName;
			int newSelectDeptId = 0;

			cout << "编号为 " << id << " 的职工已找到！" << endl<<endl;
			//展示需要修改的职工信息，便于用户对比修改
			cout << "为方便您修改，以下将展示该职工的相关信息：" << endl;
			this->m_EmpArray[index]->showInfo();

			//然后释放原职工数据
			delete this->m_EmpArray[index];

			//临时存放修改数据
			cout <<endl<< "请输入新的职工编号：";
			cin >> newId;
			cout << "请输入新的职工姓名：";
			cin >> newName;
			cout << "请输入新职工所在岗位编号：" << endl;
			cout << "1、普通员工" << endl
				 << "2、经理" << endl
				 << "3、老板" << endl;
			cin >> newSelectDeptId;

			//根据选择的不同岗位创建不同岗位的职工空间
			//创建临时存放职工的空间
			Worker* worker = NULL;
			//分支语句实现相应控件创建
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
				//异常退出处理
				cout << "新职工部门编号输入有误！" << endl;
				system("pause");
				system("cls");
				return;
			}
			//更新数组中对应的数据
			this->m_EmpArray[index] = worker;

			cout << "修改成功！" << endl;
			//重新写入修改后的职工数组中的数据并保存到文件中
			this->saveInfoToFile();
		}
		else
		{
			//不存在
			cout << "该职工编号不存在,修改失败！" << endl;
		}
	}
	//给用户留时间并清屏，提高界面的简洁性
	system("pause");
	system("cls");
}

//查找职工信息（据编号/姓名）
void WorkerManager::findEmployee()
{
	//判断文件是否存在或记录是否为空
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件数据为空，无法删除！" << endl;
	}
	else
	{
		int select = 0;
		cout << "请选择您的查找方式：" << endl;
		cout << "1、按职工编号查找" << endl
			<< "2、按职工姓名查找" << endl;
		cin >> select;

		if (select == 1)   //按编号
		{
			int id = 0;
			cout << "请输入您想查找的职工编号：";
			cin >> id;
			//判断该职工编号是否存在
			int ret = this->employeePos(id);
			if (ret != -1)
			{
				cout << "查找成功！" << endl;
				cout << "以下是您查找的编号为 " << id << " 的职工的相关信息：" << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "查无此人，查找失败！" << endl;
			}
		}
		if (select == 2)    //按姓名
		{
			string name;
			cout << "请输入您查找的职工姓名：" << endl;
			cin >> name;
			//判断是否存在该姓名的职工
			bool is_ExitFindName = false;
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					//查找到则变为true
					is_ExitFindName = true;
					//打印找到的职工信息
					cout << "查找成功！"<< "姓名为 " << name << " 的职工信息如下：" << endl;
					
					cout << "   ";   //增加缩进，提高用户观感

					//增加打印信息颜色，增强视觉效果
					HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(outHandle, 0x06);
					//调用显示信息接口
					this->m_EmpArray[i]->showInfo();
					SetConsoleTextAttribute(outHandle, 0x07);
				}
			}
			if (is_ExitFindName == false)
			{
				cout << "未找到相应姓名的职工，查找失败！" << endl;
			}
		}
	}
	//暂停和清屏
	system("pause");
	system("cls");
}

//职工排序(选择排序实现)
void WorkerManager::employeeSort()
{
	//判断文件是否存在或文件是否为空
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件为空，排序失败！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请选择您想要的排序方式：" << endl;
	cout << "1、按编号升序排列" << endl
		 << "2、按编号降序排列" << endl;

	int select = 0, sign = 3;
	//输入异常处理
	while (sign)
	{
		cin >> select;
		if ((select != 1) && (select != 2))
		{
			cout << "输入选项不存在！" << endl;
			sign--;
			if (sign == 0)
			{
				cout << "很抱歉，您输入错误次数过多，已无法进行选择！" << endl;
				system("pause");
				system("cls");
				return;
			}
			cout << "您还有" << sign << "次机会选择，" << "请重新输入：";
			continue;
		}
		break;
	}
	//选择排序
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//设置默认最小值或最大值
		int minOrMax = i;
		for (int j = i + 1; j < this->m_EmpNum; j++)
		{
			if (select == 1)   //升序
			{
				//如果后面的职工编号 小于 默认最小编号，
				//则将后一个职工位置作为默认编号最小的位置
				if (this->m_EmpArray[minOrMax]->Id > this->m_EmpArray[j]->Id)
				{
					minOrMax = j;
				}
			}
			else    //降序
			{
				//与上述同理
				if (this->m_EmpArray[minOrMax]->Id  < this->m_EmpArray[j]->Id)
				{
					minOrMax = j;
				}
			}
			
		}
		//判断第i轮比较后原最小编号位置是否变化，若变化则交换相应职工信息
		if (i != minOrMax)
		{
			//交换信息
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax] = temp;
		}
	}
	//排序完成
	cout << "排序成功！排序后职工信息如下：" << endl;
	//重写并保存排序后的职工信息至文件中
	this->saveInfoToFile();
	//显示排序后的职工信息
	this->showEmployee();   //由于显示信息函数中已经附加暂停和清屏功能，所以此时无需自加了
}

//清空文件数据
void WorkerManager::clearFileData()
{
	//判断文件是否存在或是否为空
	if (this->fileEmpty)
	{
		cout << "文件不存在或文件为空，清空失败！" << endl;
	}
	else
	{
		cout << "您确定要清空吗？" << endl;
		cout << "1、确定清空！" << endl << "2、不清空了，返回" << endl;
		int select = 0;
		cin >> select;

		//清空
		if (select == 1)
		{
			//清空文件----删除文件并重新创建一个空文件
			ofstream ofs(FILENAME, ios::trunc);
			//释放存放职工的所有空间
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					//释放并置空各个数组元素并置空
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
						this->m_EmpArray[i] = NULL;
					}
				}
				//职工数组空间释放并置空
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				//职工人数置为0
				this->m_EmpNum = 0;
				//文件清空后，判断文件为空的条件置为true
				this->fileEmpty = true;

				cout << "清空成功！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{
	//堆区内存手动开辟手动释放
	if (this->m_EmpArray != NULL)
	{
		//将每一个元素均释放
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//释放
				delete this->m_EmpArray[i];
			}
		}
		//内部元素释放完毕后再把整个空间均释放，并且置空
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}