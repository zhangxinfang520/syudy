//
// Created by lenovo on 2021-06-15.
//

#include "utils.h"
#include <string>
#include <iostream>

using namespace std;

void addPerson(Addressbooks *abs){
    if(abs->m_Size == MAX){
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }else{
        string name;
        cout <<"����������"<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		//�Ա�
		int sex = 0;
		while(true){
		    cin >> sex;
		    if (sex==1 ||sex ==2){
		        abs->personArray[abs->m_Size].m_Sex = sex;
		        break;
		    }
		    cout<<"������������������";
		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		if (age>0 && age<120){
		    abs->personArray[abs->m_Size].m_Age = age;
		}
		cout << "������绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address = "";
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//��������
		abs->m_Size ++;
		cout << "��ӳɹ�"<<endl;
		system("pause");
		system("cls");
    }
};

void showPerson(Addressbooks *abs){
    if (abs->m_Size >0){
        for (int j=0;j<abs->m_Size;j++){
            cout<<"����:"<<abs->personArray[j].m_Name<<"\t";
            cout<<"�Ա�:"<<abs->personArray[j].m_Sex<<"\t";
            cout<<"����:"<<abs->personArray[j].m_Age<<"\t";
            cout<<"�绰:"<<abs->personArray[j].m_Phone<<"\t";
            cout<<"��ַ:"<<abs->personArray[j].m_Addr<<"\t";

        }
    }else{
        cout<<"��ǰͨѶ¼Ϊ��"<<endl;
    }
    system("pause");
    system("cls");
};

int isExist(Addressbooks *abs, string name){
    for (int j=0;j<abs->m_Size;j++){
        if (abs->personArray[j].m_Name==name){
            cout <<"�û�����";
            return j;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs){
    cout<<"������Ҫɾ������ϵ��"<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if (ret !=-1){
        for (int i=ret;i < abs->m_Size;i++){
             abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size --;
    }else{
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks *abs){
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1){
	    cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}else{
	    cout<<"δ�ҵ�����";
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs){
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1){
        //����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		//�Ա�
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
    }else{
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void clearPerson(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

void showMenu(){
    cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}