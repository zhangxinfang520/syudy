//@Time : 2021-06-25 11:04
//@Author: zxf_要努力
//@File : manager.h
//经理类
#include "iostream"
#include "worker.h"
using namespace std;
#ifndef C___MANAGER_H
#define C___MANAGER_H


class Manager:public Worker {
public:
    Manager(int id,string name,int deptid);

    virtual void showInfo();
    virtual string getDeptName();


};


#endif //C___MANAGER_H
