//@Time : 2021-06-20 12:02
//@Author: zxf_ҪŬ��
//@File : 01.h
// ��ǳ������ѧϰ

/*
 ǳ�������򵥵ĸ�ֵ���� ���������� ���Ƕ������ڴ��ظ��ͷ�
 ������ڶ�����������ռ� ���п�������
 */
#include <iostream>
using namespace std;

//class Person{
//public:
//    Person(){
//        cout<<"Person ��Ĭ�Ϲ��캯��"<<endl;
//    }
//    Person(int age,int height){
//        a_Age = age;
//        a_Height  = height;
//        cout<<"Person ���в����Ĺ��캯��"<<endl;
//    }
//    ~Person(){
//        cout<<"������������"<<endl;
//    }
//
//    int a_Age;
//    int a_Height;
//};

class Person{
public:
    Person(){
        cout<<"Person ��Ĭ�Ϲ��캯��"<<endl;
    }
    Person(int age,int height){
        a_Age = age;
        a_Height  = new int(height);
        cout<<"Person ���в����Ĺ��캯��"<<endl;
    }
    Person(const Person &p){
        a_Age = p.a_Age;
        //a_Height = p.a_Height; ����Ǳ������Ĳ���
        //������� ��������һ������ڴ��ű���
        a_Height = new int(*p.a_Height);

    }
    ~Person(){
        //�������� ���������ٵ��������ͷŲ���
        if(a_Height !=NULL){
            delete a_Height;
            a_Height == NULL;
        }
        cout<<"������������"<<endl;
    }

    int a_Age;
    int* a_Height;
};

void test01(){
    Person p1(18,160);
    cout << "p1�����䣺 " << p1.a_Age << " ��ߣ� " << *p1.a_Height << endl;
    Person p2(p1);
    cout << "p1�����䣺 " << p1.a_Age << " ��ߣ� " << *p1.a_Height << endl;
}
int main(){
    test01();
}
