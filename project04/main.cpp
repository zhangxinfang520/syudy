//@Time : 2021-06-29 14:10
//@Author: zxf_ҪŬ��
//@File : main.h
//��ģ�尸��
/*
 *��������:  ʵ��һ��ͨ�õ������࣬Ҫ�����£�
    * ���Զ��������������Լ��Զ����������͵����ݽ��д洢
    * �������е����ݴ洢������
    * ���캯���п��Դ������������
    * �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
    * �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
    * ����ͨ���±�ķ�ʽ���������е�Ԫ��
    * ���Ի�ȡ�����е�ǰԪ�ظ��������������
*/
#include "iostream"
using namespace std;
#include "myArray.hpp"
#include <string>

void PrintArray(MyArray<int> &arr){
    for (int i = 0; i <arr.getSize(); ++i) {
        cout << arr[i]<<endl;
    }
}

void test(){
    MyArray<int> p(5);
    for (int i = 0; i <5 ; ++i) {
        p.Push_back(i);
    }
    PrintArray(p);

    cout<<"����������"<<p.getCapacity()<<endl;
    cout<<"����size��"<<p.getSize()<<endl;
    MyArray<int> p1(p);
    cout<<"ɾ����Ĵ�С"<<endl;
    p1.Pop_back();
     cout<<"����������"<<p1.getCapacity()<<endl;
    cout<<"����size��"<<p1.getSize()<<endl;
    PrintArray(p1);
}

class Person{
public:
    Person(){};
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};


void PrintArray1(MyArray<Person> &arr){
    for (int i = 0; i <arr.getSize(); ++i) {
        cout << arr[i].name<<" ";
        cout << arr[i].age<<" ";
        cout<<endl;
    }
}

void test01(){
    //�����Զ�������ʹ��
    Person p("zxf01",18);
    Person p2("zxf01",19);
    Person p3("zxf01",20);
    Person p4("zxf01",21);
    Person p5("zxf01",22);
    MyArray<Person> arr01(10);
    arr01.Push_back(p);
    arr01.Push_back(p2);
    arr01.Push_back(p3);
    arr01.Push_back(p4);
    arr01.Push_back(p5);
    PrintArray1(arr01);

}
int main(){
    //test();
   test01();
   system("pause");
}

