//@Time : 2021-06-28 14:31
//@Author: zxf_要努力
//@File : 05.h
//特定类型模板化
#include "iostream"

using namespace std;

class Person{
public:
    Person(string name,int age){
        m_name = name;
        m_age = age;
    }
    string m_name;
    int m_age;
};

template<class T>
bool is_equals(T& a,T& b){
    if (a==b) {
        return true;
    }else{
        return false;
    }
}

//具体的模板类
template<> bool is_equals(Person &a,Person &b){
    if (a.m_age==b.m_age && a.m_name==b.m_name){
        return true;
    }else{
        return false;
    }
}
void test(){
    Person p1 = Person("zxf",18);
    Person p2 = Person("zxf",18);
    cout<<is_equals(p1,p2)<<endl;
}
int main(){
    test();
}
