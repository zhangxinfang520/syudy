//@Time : 2021-06-25 11:04
//@Author: zxf_ҪŬ��
//@File : manager.h
//

#include "manager.h"
Manager::Manager(int id,string name,int deptid){
        this->m_Id = id;
        this->m_Name = name;
        this->m_Deptid = deptid;
}
void Manager::showInfo(){
    cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ϰ彻��������" << endl;
};
string Manager::getDeptName(){
    return "����ϰ��������";
}
