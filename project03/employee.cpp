//@Time : 2021-06-25 10:33
//@Author: zxf_要努力
//@File : employee.h
//
#include "employee.h"

Employee::Employee(int id,string name,int deptid){
        this->m_Id = id;
        this->m_Name = name;
        this->m_Deptid = deptid;
}
void Employee::showInfo(){
    cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成经理交给的任务" << endl;
};
string Employee::getDeptName(){
    return "完成经理给的任务";
}