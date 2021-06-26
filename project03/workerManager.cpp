//@Time : 2021-06-25 9:28
//@Author: zxf_ҪŬ��
//@File : workerManager.h
//

#include "workerManager.h"

workerManager::workerManager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        //cout<<"�ļ�������"<<endl;
        this->m_EmpNum = 0; //��ʼ������
        this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    //�ж�Ϊ�յ����
    char ch;
    ifs>>ch;
    if(ifs.eof()){
       // cout <<"�ļ�Ϊ��"<<endl;
        this -> m_EmpNum = 0;
        this -> m_EmpArray = NULL;
        this -> m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    //cout << "ְ������Ϊ��" << num << endl;  //���Դ���
	this->m_EmpNum = num;  //���³�Ա����
	this ->m_EmpArray = new Worker *[this->m_EmpNum];
	init_Emp();
//	for (int i = 0; i < m_EmpNum; i++)
//	{
//		cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
//			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
//			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_Deptid << endl;
//	}
}
void workerManager::Show_menu() {
    cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workerManager::Exit_system(){
    cout <<"��ӭ�´�ʹ��" <<endl;
    system("pause");
    exit(0);
};

void workerManager::Add_Emp(){
    cout<<"������Ҫ����Ա��������"<<endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0){
        //���¼���ռ�Ĵ�С
        int newSize = this -> m_EmpNum + addNum;
        //�����¿ռ�
        Worker **newSpace = new Worker *[newSize];
        //��ԭ�ռ������ݴ�ŵ��¿ռ���
        if (this->m_EmpArray !=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i] = this -> m_EmpArray[i];
            }
        }
       //�����µ�����
       for(int i=0;i<addNum;i++){
           int id;
           string name;
           int dSelect;
           cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
           cin >> id;
           cout << "������� " << i + 1 << " ����ְ��������" << endl;
           cin >> name;
           cout << "��ѡ���ְ���ĸ�λ��" << endl;
           cout << "1����ְͨ��" << endl;
           cout << "2������" << endl;
           cout << "3���ϰ�" << endl;
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

       //����
       //�ͷ�ԭ�пռ�
       delete [] this -> m_EmpArray;
       //�����¿ռ��ָ��
       this -> m_EmpArray = newSpace;
       //�����µĸ���
       this -> m_EmpNum = newSize;

		//��ʾ��Ϣ
		this -> save();
		this-> m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

    } else{
        cout << "��������" << endl;
    }
    system("pause");
    system("cls");
}

void workerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios_base::out);//��д��ķ�ʽ����ȡ
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
        //��¼����
        num ++;
    }
    ifs.close();
    return  num;
}

void workerManager::show_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�������κ�Ա��"<<endl;
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
        cout<<"�ļ���¼Ϊ�� �޷�ɾ��"<<endl;
        return;
    }else{
        cout<<"��������Ҫɾ����Ա���ı��"<<endl;
        int id;
        cin>> id;
        int index = this->IsExist(id);
        if (index != -1){
            for(int i = index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum --;
            cout<<"ɾ���ɹ�"<<endl;
            this->save();//�����ı��ļ�
        }else{
            cout<<"δ�鵽����ɾ��ʧ��"<<endl;
        }
    };
    system("pause");
    system("cls");
};

void workerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"Ա���б�Ϊ�� �޷��޸�"<<endl;
    }else{
        int id;
        cout <<"������Ҫ�޸�Ա���ı��"<<endl;
        cin>>id;
        int index = this->IsExist(id);
        if (index != -1){
            int new_id = 0;
            string new_name = "";
            int new_deptid = 0;
            delete this->m_EmpArray[index];
            cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
            cin>>new_id;
            cout << "�������������� " << endl;
            cin>>new_name;

            cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ�"<<endl;
			this->save();
        } else{
            cout<<"δ�鵽����"<<endl;
        }
    }
    system("pause");
    system("cls");
};

void workerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"�ļ���¼Ϊ��,�޷�����"<<endl;
    }else{
        int select;
        cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		cin>>select;
		if(select ==1){
		    int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index!=-1){
			    cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
			    this->m_EmpArray[index]->showInfo();
			} else
			    cout<<"����ʧ��"<<endl;
		}else if(select==2){
		    string name;
		    cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;
			for(int i=0;i< this->m_EmpNum;i++){
			    if(this->m_EmpArray[i]->m_Name==name){
			        cout << "���ҳɹ�,ְ�����Ϊ��"
                           << m_EmpArray[i]->m_Id
                           << " �ŵ���Ϣ���£�" << endl;
			        flag = true;
			        this->m_EmpArray[i]->showInfo();
			    }
			}
			if (!flag){
			    //���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}else{
		    cout << "����ѡ������" << endl;
		}
    }
    system("pause");
	system("cls");
}

void workerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ�������"<<endl;
        system("pause");
        system("cls");
    }else{
       cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
        for (int i = 0; i < this->m_EmpNum; ++i) {
            int minOrMax = i;
            for (int j = i+1; j < this->m_EmpNum ; ++j) {
                if (select == 1) //����
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}else  //����
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
        cout<<"����ɹ�"<<endl;
        this->show_Emp();
        this->save();
    }

}

void workerManager::Clean_File(){
    cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

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
       cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager(){
    if (this->m_EmpArray !=NULL){
        delete[] this->m_EmpArray;
    }
}

