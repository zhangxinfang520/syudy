//@Time : 2021-06-25 11:04
//@Author: zxf_要努力
//@File : manager.h
//

#include "manager.h"
Manager::Manager(int id,string name,int deptid){
        this->m_Id = id;
        this->m_Name = name;
        this->m_Deptid = deptid;
}
void Manager::showInfo(){
    cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成老板交给的任务" << endl;
};
string Manager::getDeptName(){
    return "完成老板给的任务";
}
