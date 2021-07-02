//@Time : 2021-06-30 9:54
//@Author: zxf_要努力
//@File : 02.h
//vector 操作自己的容器
#include "iostream"
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

class Person{
public:
    Person(string name ,int age){
        this->name =name;
        this->age= age;
    }
    string name;
    int age;
};

void test01(){
    vector<Person> pv;
    Person p("zxf",10);
    Person p1("zxf1",20);
    Person p2("zxf2",30);
    Person p3("zxf3",40);
    pv.push_back(p);
    pv.push_back(p1);
    pv.push_back(p2);
    pv.push_back(p3);

    //遍历
    for (vector<Person>::iterator q = pv.begin();  q!=pv.end() ; q++) {
        cout<<"name: " << (*q).name <<" age: " <<(*q).age << endl;
        cout<<"name: " << q->name <<" age: " << q->age << endl;
    }
}

void test02(){
    vector<Person *> pp;
    Person p("zxf",10);
    Person p1("zxf1",20);
    Person p2("zxf2",30);
    Person p3("zxf3",40);
    pp.push_back(&p1);
    pp.push_back(&p2);
    pp.push_back(&p3);
    pp.push_back(&p);
    for (vector<Person *>::iterator v = pp.begin(); v!=pp.end() ; v++) {
        cout<<"name: " << (*(*v)).name <<" age: " << (*(*v)).age << endl;
        cout<<"-----"<<endl;
        cout<<"name: " << (*v)->name <<" age: " << (*v)->age << endl;
    }

}

int main(){
    //test01();
    test02();
}

