//@Time : 2021-06-25 10:53
//@Author: zxf_ҪŬ��
//@File : test.h
//������
#include "iostream"
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test(){
    Worker *woker = new Employee(1,"���η�",1);
    woker->showInfo();
    delete woker;
    woker = new Manager(2,"���η�02",2);
    woker ->showInfo();
    delete woker;
    woker = new Boss(3,"���η�03",3);
    woker -> showInfo();
    delete woker;
}
int main(){
    test();
}
