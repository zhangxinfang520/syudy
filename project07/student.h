//@Time : 2021-07-06 15:15
//@Author: zxf_要努力
//@File : student.h
//
#pragma once
#include "iostream"
#include "vector"
#include "globalFile.h"
#include "fstream"
#include "Identity.h"

#include "computerRoom.h"

#ifndef C___STUDENT_H
#define C___STUDENT_H
using namespace std;

class Student:public Identity {
public:
    Student();
    Student(int id,string name,string pwd);
    virtual void operMenu();
    void applyOrder();
    void showMyOrder();
    //查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
    //学生学号
    int m_Id;
    vector<ComputerRoom> vCom;
};


#endif //C___STUDENT_H
