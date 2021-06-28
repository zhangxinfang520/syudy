//@Time : 2021-06-28 15:05
//@Author: zxf_要努力
//@File : 07.h
// 类模板对象做函数的参数传入
#include "iostream"
using namespace std;
#include <string>
#include<typeinfo>


template<class T1,class T2>
class Person{
public:
    Person(T1 name,T2 age){
        this->name = name;
        this->age=age;
    }
    void ShowInfo(){
        cout<<" name: "<<this->name<<" age:"<<this->age<<endl;
    }
    T1 name;
    T2 age;
};

//指定传入的类型   --- 直接显示对象的数据类型
void printPerson1(Person<string,int> &p){
    p.ShowInfo();
}
void test01(){
    Person<string,int>p("zxf",18);
    printPerson1(p);
}
//参数模板化           --- 将对象中的参数变为模板进行传递
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p){
    p.ShowInfo();
    cout << "T1的类型为： " << typeid(T1).name() << endl;
    cout << "T2的类型为： " << typeid(T2).name() << endl;
}
void test02(){
    Person<string,int>p("zxf01",18);
    printPerson2(p);
}
//整个类模板化       --- 将这个对象类型 模板化进行传递
template<class T>
void printPerson3(T &p){
    p.ShowInfo();
}
void test03(){
     Person<string,int>p("zxf02",18);
     printPerson3(p);
}
int main(){
    test01();
    test02();
    test03();
}