//@Time : 2021-06-25 9:28
//@Author: zxf_要努力
//@File : workerManager.h
//

#include "workerManager.h"

workerManager::workerManager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        //cout<<"文件不存在"<<endl;
        this->m_EmpNum = 0; //初始化人数
        this->m_FileIsEmpty = true;//初始化文件为空标志
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    //判断为空的情况
    char ch;
    ifs>>ch;
    if(ifs.eof()){
       // cout <<"文件为空"<<endl;
        this -> m_EmpNum = 0;
        this -> m_EmpArray = NULL;
        this -> m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    //cout << "职工个数为：" << num << endl;  //测试代码
	this->m_EmpNum = num;  //更新成员属性
	this ->m_EmpArray = new Worker *[this->m_EmpNum];
	init_Emp();
//	for (int i = 0; i < m_EmpNum; i++)
//	{
//		cout << "职工号： " << this->m_EmpArray[i]->m_Id
//			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
//			<< " 部门编号： " << this->m_EmpArray[i]->m_Deptid << endl;
//	}
}
void workerManager::Show_menu() {
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workerManager::Exit_system(){
    cout <<"欢迎下次使用" <<endl;
    system("pause");
    exit(0);
};

void workerManager::Add_Emp(){
    cout<<"请输入要加入员工的人数"<<endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0){
        //重新计算空间的大小
        int newSize = this -> m_EmpNum + addNum;
        //开辟新空间
        Worker **newSpace = new Worker *[newSize];
        //将原空间下内容存放到新空间下
        if (this->m_EmpArray !=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i] = this -> m_EmpArray[i];
            }
        }
       //输入新的数据
       for(int i=0;i<addNum;i++){
           int id;
           string name;
           int dSelect;
           cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
           cin >> id;
           cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
           cin >> name;
           cout << "请选择该职工的岗位：" << endl;
           cout << "1、普通职工" << endl;
           cout << "2、经理" << endl;
           cout << "3、老板" << endl;
           cin >> dSelect;
           Worker *worker = NULL;
           switch (dSelect){
               case 1:
                   worker = new Employee(id,name,dSelect);
                   break;
               case 2:
                   worker = new Manager(id,name,dSelect);
                   break;
               case 3:
                   worker = new Boss(id,name,dSelect);
                   break;
               default:
                       break;
           }
           newSpace[this->m_EmpNum + i] = worker;
       }

       //更新
       //释放原有空间
       delete [] this -> m_EmpArray;
       //更改新空间的指向
       this -> m_EmpArray = newSpace;
       //更新新的个数
       this -> m_EmpNum = newSize;

		//提示信息
		this -> save();
		this-> m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工！" << endl;

    } else{
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

void workerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios_base::out);//以写入的方式来读取
    for (int i=0;i<this->m_EmpNum;i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Deptid << endl;
    }
    ofs.close();
}

void workerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs>>name&&ifs>>dId){
        Worker *worker = NULL;
        if(dId==1){
            worker = new Employee(id,name,dId);
        }else if(dId==2){
            worker = new Manager(id,name,dId);
        } else{
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index ++;
    }
};

int workerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs>>id && ifs >>name&&ifs>>dId){
        //记录人数
        num ++;
    }
    ifs.close();
    return  num;
}

void workerManager::show_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"不存在任何员工"<<endl;
        return;
    }else{
        for (int i = 0; i < this->m_EmpNum; ++i) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
};

int workerManager::IsExist(int id){
    int index = -1;
    for (int i=0;i<this->m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_Id==id){
            index = i;
            break;
        }
    }
    return index;
};

void workerManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件记录为空 无法删除"<<endl;
        return;
    }else{
        cout<<"请输入你要删除的员工的编号"<<endl;
        int id;
        cin>> id;
        int index = this->IsExist(id);
        if (index != -1){
            for(int i = index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum --;
            cout<<"删除成功"<<endl;
            this->save();//更新文本文件
        }else{
            cout<<"未查到此人删除失败"<<endl;
        }
    };
    system("pause");
    system("cls");
};

void workerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"员工列表为空 无法修改"<<endl;
    }else{
        int id;
        cout <<"请输入要修改员工的编号"<<endl;
        cin>>id;
        int index = this->IsExist(id);
        if (index != -1){
            int new_id = 0;
            string new_name = "";
            int new_deptid = 0;
            delete this->m_EmpArray[index];
            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin>>new_id;
            cout << "请输入新姓名： " << endl;
            cin>>new_name;

            cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin>>new_deptid;

			Worker *worker = NULL;
			switch(new_deptid){
			    case 1:
			    worker = new Employee(new_id,new_name,new_deptid);
			    break;
			    case 2:
			    worker = new Manager(new_id,new_name,new_deptid);
			    break;
			    case 3:
			    worker = new Boss(new_id,new_name,new_deptid);
			    break;
			    default:
			        break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功"<<endl;
			this->save();
        } else{
            cout<<"未查到此人"<<endl;
        }
    }
    system("pause");
    system("cls");
};

void workerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"文件记录为空,无法查找"<<endl;
    }else{
        int select;
        cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		cin>>select;
		if(select ==1){
		    int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index!=-1){
			    cout << "查找成功！该职工信息如下：" << endl;
			    this->m_EmpArray[index]->showInfo();
			} else
			    cout<<"查找失败"<<endl;
		}else if(select==2){
		    string name;
		    cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;
			for(int i=0;i< this->m_EmpNum;i++){
			    if(this->m_EmpArray[i]->m_Name==name){
			        cout << "查找成功,职工编号为："
                           << m_EmpArray[i]->m_Id
                           << " 号的信息如下：" << endl;
			        flag = true;
			        this->m_EmpArray[i]->showInfo();
			    }
			}
			if (!flag){
			    //查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}else{
		    cout << "输入选项有误" << endl;
		}
    }
    system("pause");
	system("cls");
}

void workerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在"<<endl;
        system("pause");
        system("cls");
    }else{
       cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
        for (int i = 0; i < this->m_EmpNum; ++i) {
            int minOrMax = i;
            for (int j = i+1; j < this->m_EmpNum ; ++j) {
                if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
            }
            if (minOrMax!=i){
                Worker *temp = this -> m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = m_EmpArray[i];
                m_EmpArray[i] = temp;
            }
        }
        cout<<"排序成功"<<endl;
        this->show_Emp();
        this->save();
    }

}

void workerManager::Clean_File(){
    cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if(select == 1){
	    ofstream ofs;
	    ofs.open(FILENAME,ios::trunc);
	    ofs.close();
	    if(this->m_EmpArray !=NULL){
            for (int i = 0; i <this->m_EmpNum ; ++i) {
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
	    }
       cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager(){
    if (this->m_EmpArray !=NULL){
        delete[] this->m_EmpArray;
    }
}

