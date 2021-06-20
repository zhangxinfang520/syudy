//@Time : 2021-06-20 16:33
//@Author: zxf_要努力
//@File : 06.h
// this 指针的用法
/*
 this指针是隐含每一个非静态成员函数内的一种指针
 this指针不需要定义，直接使用即可
this指针的用途：
    *  当形参和成员变量同名时，可用this指针来区分
    *  在类的非静态成员函数中返回对象本身，可使用return *this

 */
#include "iostream"
using namespace std;

class Person{
public:
    Person(int age){
        //当形参和成员变量同名时，可用this指针来区分
        this->age=age;
    }
    //如果在Person后面 添加&返回的是一个值
    Person& addPerson(Person p){
        this->age += p.age;
        return *this;
    }
    int age;
};

void test01(){
    Person p1(10);
    cout << "p1.age: "<<p1.age<<endl;
    Person p2(10);
    p2.addPerson(p1).addPerson(p1).addPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}
int main(){
    test01();
}

