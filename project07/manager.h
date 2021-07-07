//@Time : 2021-07-06 16:42
//@Author: zxf_要努力
//@File : manager.h
//
#pragma once
#include <iostream>
#include "vector"
#include "fstream"
#include "algorithm"
#include "globalFile.h"
#include "teacher.h"
#include "student.h"

using namespace std;
#ifndef C___MANAGER_H
#define C___MANAGER_H
#include "Identity.h"
#include "computerRoom.h"


class Manager:public Identity {
public:
    Manager();

    Manager(string name,string pwd);
    //选择菜单
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
    //检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);
	//为了去重操作添加的容器
	void initVector();
	//学生容器
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;
};


#endif //C___MANAGER_H
