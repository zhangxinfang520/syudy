//@Time : 2021-06-25 10:33
//@Author: zxf_ҪŬ��
//@File : employee.h
//
#include "employee.h"

Employee::Employee(int id,string name,int deptid){
        this->m_Id = id;
        this->m_Name = name;
        this->m_Deptid = deptid;
}
void Employee::showInfo(){
    cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
};
string Employee::getDeptName(){
    return "��ɾ����������";
}