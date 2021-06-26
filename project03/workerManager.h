//@Time : 2021-06-25 9:28
//@Author: zxf_要努力
//@File : workerManager.h
//
#pragma once
#ifndef C___WORKERMANAGER_H
#define C___WORKERMANAGER_H
#include "iostream"
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "fstream"
#define FILENAME "../project03/empFile.txt"

class workerManager {
public:
    workerManager();
    //显示菜单
    void Show_menu();
    //记录人数
    int m_EmpNum;
    //员工数组的指针
    Worker **m_EmpArray;
    //退出系统
    void Exit_system();
    //添加员工
    void Add_Emp();
    //保存
    void save();
    //初始化员工列表
    void init_Emp();
    //显示员工列表
    void show_Emp();
    //获取员工数目
    int get_EmpNum();
    //标志文件是否为空
    bool m_FileIsEmpty;
    //判断若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);
    //删除员工
    void Del_Emp();
    //修改职工
    void Mod_Emp();
    //查找员工
    void Find_Emp();
    //排序
    void Sort_Emp();
    //清空
    void Clean_File();

    ~workerManager();
};


#endif //C___WORKERMANAGER_H
