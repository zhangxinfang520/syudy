//@Time : 2021-06-19 16:58
//@Author: zxf_ҪŬ��
//@File : 03.h
//���캯���Ĺ��췽ʽ
/*
 ��������Ϊ�� �вι�����޲ι���
 �����ͷ�Ϊ�� ��ͨ����Ϳ�������

 ���÷�ʽ��
    ���ŷ� ��ʾ�� ��ʽת����

���캯�����ù������£�
    * ����û������вι��캯����c++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
    * ����û����忽�����캯����c++�������ṩ��������
�����������÷�
    * ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
    * ֵ���ݵķ�ʽ������������ֵ
    * ��ֵ��ʽ���ؾֲ�����
 */
#include <iostream>
using namespace std;

class Person{
public:
     Person(){
        cout<<"�޲ι��캯��"<<endl;
    }
     Person(int age){
        cout<<"�вι��캯��"<<endl;
        age = age;
    }
    Person(const Person &p){
        age = p.age;
        cout<<"copy�ι��캯��"<<endl;
    }
    ~Person(){
         cout<<"�����캯��"<<endl;
    }
private:
    int age;
};
// 2���캯���ĵ���

void test(){
    //�޲ι��캯��
    Person p;
}
//�����вεĹ��캯��
void test02(){
    //���ŷ�
    Person p1(10);
    //ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
	//Person p2();
	//��ʾ��
	Person p2 = Person(10);
	Person p3 = Person(p2);
	//Person(10)����д������������  ��ǰ�н���֮����������

	//2.3 ��ʽת����
	Person p4 = 10; // Person p4 = Person(10);
	Person p5 = p4; // Person p5 = Person(p4);
	//ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
	//Person p5(p4);

}

int main(){
    test();
    test02();
};

