//
// Created by lenovo on 2021-06-15.
//

#include "utils.h"
#include <string>
#include <iostream>

using namespace std;

void addPerson(Addressbooks *abs){
    if(abs->m_Size == MAX){
        cout << "通讯录已满，无法添加" << endl;
        return;
    }else{
        string name;
        cout <<"请输入姓名"<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		//性别
		int sex = 0;
		while(true){
		    cin >> sex;
		    if (sex==1 ||sex ==2){
		        abs->personArray[abs->m_Size].m_Sex = sex;
		        break;
		    }
		    cout<<"输入有误，请重新输入";
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		if (age>0 && age<120){
		    abs->personArray[abs->m_Size].m_Age = age;
		}
		cout << "请输入电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address = "";
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新人数
		abs->m_Size ++;
		cout << "添加成功"<<endl;
		system("pause");
		system("cls");
    }
};

void showPerson(Addressbooks *abs){
    if (abs->m_Size >0){
        for (int j=0;j<abs->m_Size;j++){
            cout<<"姓名:"<<abs->personArray[j].m_Name<<"\t";
            cout<<"性别:"<<abs->personArray[j].m_Sex<<"\t";
            cout<<"年龄:"<<abs->personArray[j].m_Age<<"\t";
            cout<<"电话:"<<abs->personArray[j].m_Phone<<"\t";
            cout<<"地址:"<<abs->personArray[j].m_Addr<<"\t";

        }
    }else{
        cout<<"当前通讯录为空"<<endl;
    }
    system("pause");
    system("cls");
};

int isExist(Addressbooks *abs, string name){
    for (int j=0;j<abs->m_Size;j++){
        if (abs->personArray[j].m_Name==name){
            cout <<"用户存在";
            return j;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs){
    cout<<"请输入要删除的联系人"<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if (ret !=-1){
        for (int i=ret;i < abs->m_Size;i++){
             abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size --;
    }else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks *abs){
    cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1){
	    cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}else{
	    cout<<"未找到此人";
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs){
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1){
        //姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
    }else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void clearPerson(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

void showMenu(){
    cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}