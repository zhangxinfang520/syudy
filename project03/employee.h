//@Time : 2021-06-25 10:33
//@Author: zxf_要努力
//@File : employee.h
//
#include "worker.h"
#include "iostream"
#include <string>
using namespace std;
#ifndef C___EMPLOYEE_H
#define C___EMPLOYEE_H


class Employee: public Worker {
public:
    Employee(int id, string name,int deptid);
    virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();

};


#endif //C___EMPLOYEE_H
