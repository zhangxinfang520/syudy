//@Time : 2021-06-20 13:07
//@Author: zxf_ҪŬ��
//@File : 03.h
// ��һ������Ϊ��Ա����ʱ ����˳��
#include "iostream"
using namespace std;

class Phone{
public:
    Phone(string name){
        cout<<"phone�Ĺ��캯��"<<endl;
        i_name = name;
    }
    ~Phone(){
        cout<<"phone����������"<<endl;
    }
    string i_name;
};

class Person{
public:
    Person(string name,string phone_name):m_name(name),i_name(phone_name){
        cout<<"Person�Ĺ��캯��"<<endl;
    }
    ~Person(){
        cout<<"Person����������"<<endl;
    }
    string m_name;
    Phone i_name;
};

void test(){
    //�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴
    Person p("zxf","iphone");
    cout << p.m_name<< p.i_name.i_name<<endl;
}
int main(){
    test();
}

