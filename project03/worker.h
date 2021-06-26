//@Time : 2021-06-25 10:26
//@Author: zxf_要努力
//@File : worker.h
//职工的抽象类
#pragma once
#include "iostream"
using namespace std;
#ifndef C___WORKER_H
#define C___WORKER_H

class Worker{
public:
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    int m_Id;
    string m_Name;
    int m_Deptid;
};
#endif //C___WORKER_H
