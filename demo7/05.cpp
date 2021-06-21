//@Time : 2021-06-21 13:56
//@Author: zxf_要努力
//@File : 05.h
// 左移运算符的重载
#include "iostream"
using namespace std;

class Person{
    friend ostream &operator<<(ostream &cout,Person &p);
public:
    Person(int a,int b){
        m_a = a;
        m_b = b;
    }

private:
    int m_a;
    int m_b;
};

ostream& operator<<(ostream &cout,Person &p){
    cout<<"m_a: "<<p.m_a << " b:" << p.m_b;
    return cout;
}
void test(){
    Person p(10,20);
    cout << p<<endl;
}

int main(){
    test();
}

