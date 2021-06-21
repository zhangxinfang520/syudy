//@Time : 2021-06-21 13:37
//@Author: zxf_要努力
//@File : 04.h
//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号运算符重载 作用：实现两个自定义数据类型相加的运算
#include "iostream"
using namespace std;

class Person{
public:
    Person(){};
    Person(int a,int b){
        m_a = a;
        m_b = b;
    }
//    Person operator+(const Person& a){
//        Person temp;
//        temp.m_a = this->m_a + a.m_a;
//        temp.m_b = this->m_b + a.m_b;
//        return temp;
//    }
    int m_a;
    int m_b;
};
//全局函数的重写
Person operator+(const Person& a ,const Person &b){
    Person temp;
    temp.m_a = a.m_a + b.m_a;
    temp.m_b = a.m_b + b.m_b;
    return temp;
}
Person operator+(const Person& a ,int value){
    Person temp;
    temp.m_a = a.m_a + value;
    temp.m_b = a.m_b + value;
    return temp;
}

void test01(){
    Person a(10,20);
    Person b (20,30);
    //Person c = a.operator+(b); 二者等价
    Person c = a + b;
    Person d = b + 100;
    cout << c.m_a<<endl;
    cout << d.m_a<<endl;

}

int main(){
    test01();
}
