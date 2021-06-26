//@Time : 2021-06-25 11:16
//@Author: zxf_要努力
//@File : boss.h
//
#include "iostream"
#include "worker.h"
using namespace std;
#ifndef C___BOSS_H
#define C___BOSS_H


class Boss:public Worker {
public:
    Boss(int id,string name,int deptid);
    virtual void showInfo();
    virtual string getDeptName();
};


#endif //C___BOSS_H
