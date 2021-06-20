//@Time : 2021-06-20 13:07
//@Author: zxf_要努力
//@File : 03.h
// 当一个类作为成员变量时 构造顺序
#include "iostream"
using namespace std;

class Phone{
public:
    Phone(string name){
        cout<<"phone的构造函数"<<endl;
        i_name = name;
    }
    ~Phone(){
        cout<<"phone的析构函数"<<endl;
    }
    string i_name;
};

class Person{
public:
    Person(string name,string phone_name):m_name(name),i_name(phone_name){
        cout<<"Person的构造函数"<<endl;
    }
    ~Person(){
        cout<<"Person的析构函数"<<endl;
    }
    string m_name;
    Phone i_name;
};

void test(){
    //当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
    Person p("zxf","iphone");
    cout << p.m_name<< p.i_name.i_name<<endl;
}
int main(){
    test();
}

