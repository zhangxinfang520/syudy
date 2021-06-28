//@Time : 2021-06-28 15:05
//@Author: zxf_ҪŬ��
//@File : 07.h
// ��ģ������������Ĳ�������
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

//ָ�����������   --- ֱ����ʾ�������������
void printPerson1(Person<string,int> &p){
    p.ShowInfo();
}
void test01(){
    Person<string,int>p("zxf",18);
    printPerson1(p);
}
//����ģ�廯           --- �������еĲ�����Ϊģ����д���
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p){
    p.ShowInfo();
    cout << "T1������Ϊ�� " << typeid(T1).name() << endl;
    cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
}
void test02(){
    Person<string,int>p("zxf01",18);
    printPerson2(p);
}
//������ģ�廯       --- ������������� ģ�廯���д���
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