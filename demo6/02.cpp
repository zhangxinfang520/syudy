//@Time : 2021-06-20 12:51
//@Author: zxf_要努力
//@File : 02.h
//初始化列表
//用列表来初始化属性
#include "iostream"
using namespace std;


class Person{
public:
    //传统方式
//    Person(int m_a,int m_b,int m_c){
//        m_A = m_a;
//        m_B = m_b;
//        m_C = m_c;
//    }
    Person(int a,int b, int c): m_A(a),m_B(b),m_C(c){

    }
    int m_A;
    int m_B;
    int m_C;

};
int main(){
    Person p(1,2,3);
    cout <<p.m_A<<endl;
    cout <<p.m_B<<endl;
    cout <<p.m_C<<endl;
}

