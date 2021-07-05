//@Time : 2021-07-04 13:06
//@Author: zxf_要努力
//@File : work_map.h
//
//* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
//* 随机给10名员工分配部门和工资
//* 通过multimap进行信息的插入  key(部门编号) value(员工)
//* 分部门显示员工信息
#include "iostream"
#include <vector>
#include "algorithm"
#include <map>
#include "string"
#include "ctime"

using namespace std;
//部分定义
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{
public:
    string name;
    int  m_Salary;
};

void printVector(vector<Worker> &v){
    for (vector<Worker>::iterator i = v.begin(); i != v.end() ; ++i) {
        cout << "work name: " << (*i).name << " work salary: " << (*i).m_Salary<<endl;
    }
}
void  crate_worker_team(vector<Worker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i <10 ; ++i) {
        Worker w;
        w.name = "emplyoee";
        w.name +=nameSeed[i];
        w.m_Salary = rand() %10000 + 10000;
        v.push_back(w);
    }
}

//员工分组
void setGroup(vector<Worker> &v,multimap<int,Worker> &m){

    for (vector<Worker>::iterator i = v.begin(); i !=v.end() ; ++i) {
        //随机产生部门
        int deptid = rand() % 3;
        m.insert(make_pair(deptid,*i));
    }
}

void show_all_info(multimap<int,Worker> &w){
    cout << "策划部门：" << endl;
    multimap<int,Worker>::iterator pos = w.find(CEHUA);
    int count = w.count(CEHUA);
    int index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name: " <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
    cout << "美术部门：" << endl;
    pos = w.find(MEISHU);
    count = w.count(MEISHU);
    index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name :" <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
    cout << "研发部门：" << endl;
    pos = w.find(YANFA);
    count = w.count(YANFA);
    index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name : " <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
}

void test(){
    srand((unsigned int) time(NULL));
    vector<Worker> v;
    crate_worker_team(v);
    printVector(v);
    multimap<int,Worker> w;
    setGroup(v,w);
    show_all_info(w);
}


int main(){
    test();
}


