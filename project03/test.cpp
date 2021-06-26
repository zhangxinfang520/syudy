//@Time : 2021-06-25 10:53
//@Author: zxf_要努力
//@File : test.h
//测试类
#include "iostream"
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test(){
    Worker *woker = new Employee(1,"张鑫方",1);
    woker->showInfo();
    delete woker;
    woker = new Manager(2,"张鑫方02",2);
    woker ->showInfo();
    delete woker;
    woker = new Boss(3,"张鑫方03",3);
    woker -> showInfo();
    delete woker;
}
int main(){
    test();
}
