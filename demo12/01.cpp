//@Time : 2021-06-29 11:36
//@Author: zxf_要努力
//@File : 01.h
//类模板的成员函数 外部实现
#include "iostream"
using namespace std;
#include <string>

template <class T1,class T2>
class Person{
public:
    Person(T1 name,T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};

template <class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->m_Name = name;
    this->m_Age = age;
}

template <class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void test(){
    Person<string,int> p("TOM",12);
    p.showPerson();
}

int main(){
    test();
}
