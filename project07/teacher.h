//@Time : 2021-07-06 15:46
//@Author: zxf_要努力
//@File : teacher.h
//
#pragma once
#include "iostream"
#include "fstream"
#include "orderFile.h"
#include "vector"
using namespace std;
#ifndef C___TEACHER_H
#define C___TEACHER_H
#include "Identity.h"

class Teacher: public Identity{
public:
    Teacher();
    //有参构造 (职工编号，姓名，密码)
    Teacher(int empId,string name,string pwd);
    //菜单界面
    virtual void operMenu();
    //查看所有预约
    void showAllOrder();
    //审核预约
    void validOrder();
    //教师编号
    int m_EmpId;
};


#endif //C___TEACHER_H
