//@Time : 2021-06-25 11:16
//@Author: zxf_ҪŬ��
//@File : boss.h
//

#include "boss.h"


Boss::Boss(int id,string name,int deptid){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Deptid = deptid;
};
void Boss::showInfo(){
     cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺰�������" << endl;
};
string Boss::getDeptName(){
    return string("i am a boss ");
};
