//@Time : 2021-06-25 11:16
//@Author: zxf_要努力
//@File : boss.h
//

#include "boss.h"


Boss::Boss(int id,string name,int deptid){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Deptid = deptid;
};
void Boss::showInfo(){
     cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：安排任务" << endl;
};
string Boss::getDeptName(){
    return string("i am a boss ");
};
