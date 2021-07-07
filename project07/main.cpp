//@Time : 2021-07-06 14:09
//@Author: zxf_ҪŬ��
//@File : main.h
// ����ԤԼϵͳ
#include "iostream"
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>
#include <string>

using namespace std;

void managerMenu(Identity * &manager){
    while(true){
        //����Ա�˵�
        manager->operMenu();
        Manager* man = (Manager*) manager;
        int select = 0;
        cin>> select;
        if(select == 1){
            cout << "����˺�" << endl;
			man->addPerson();
        }else if(select == 2){
            cout << "�鿴�˺�" << endl;
			man->showPerson();
        }else if(select == 3){
            cout << "�鿴����" << endl;
			man->showComputer();
        }else if(select == 4){
            cout << "���ԤԼ" << endl;
			man->cleanFile();
        }else{
            delete manager;
            cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
        }
    }
}

//ѧ���˵�
void studentMenu(Identity * &student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//ʵ�ֵ�½����
void LoginIn(string filename,int type){
    Identity *person = NULL;
    ifstream ifs;
    ifs.open(filename,ios::in);
    //�ļ������ڵ����
    if(!ifs.is_open()){
        cout<< "file is not exist" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;

    if(type == 1){
        // student login
        cout << " please input stuID"<<endl;
        cin >> id;
    }else if(type == 2){
        cout << "please input teaID"<<endl;
        cin >> id;
    }
    cout << "please input username" << endl;
    cin >> name;
    cout << "please input password" << endl;
    cin >> pwd;

    if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while(ifs>>fId && ifs>>fName && ifs>>fPwd){
		    if (id == fId && name == fName && pwd == fPwd){
		        		cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
                studentMenu(person);
				return;
		    }
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
                TeacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		//����Ա��¼��֤
        string fName;
        string fPwd;
        while(ifs>>fName && ifs>>fPwd){
            if(name==fName && pwd==fPwd){
                cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
//				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name,pwd);
				//�������Ա�˵�
                managerMenu(person);
            }
        }
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;

}

int main(){
    while(true){
        cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
         << endl;
        cout << endl << "�������������" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.ѧ������           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.��    ʦ           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.�� �� Ա           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.��    ��           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "��������ѡ��: ";
        int select = 0;
        cin >> select;
        switch(select){
            case 1://ѧ������
                LoginIn(STUDENT_FILE,1);
                break;
            case 2://��ʦ����
             LoginIn(TEACHER_FILE,2);
                break;
            case 3://����Ա����
             LoginIn(ADMIN_FILE,3);
                break;
            case 0:
                cout <<"exit system"<<endl;
                exit(0);
                break;
            default:
                exit(0);
                cout <<"exit system"<<endl;
                break;
        }
    }

}

