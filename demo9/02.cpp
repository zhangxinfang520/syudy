//@Time : 2021-06-23 16:11
//@Author: zxf_ҪŬ��
//@File : 02.h
//���������ʹ���������

//��̬ʹ��ʱ����������������Կ��ٵ�������
//��ô����ָ�����ͷ�ʱ�޷����õ��������������
#include "iostream"
using namespace std;
#include <string>

class Animal{
public:
    Animal(){
        cout <<"Animal �Ĺ��캯��"<<endl;
    }
    virtual void say()=0;

    // ������Ǵ���������ͨ�����ഴ��������� �޷������������������
//    ~Animal(){
//        cout<<"Animal ����������"<<endl;
//    }
    //���������� ҲҪ��ʵ�ֵ�
    virtual ~Animal()=0;
};

Animal::~Animal(){
    cout<<"Animal �Ĵ���������"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout <<"���� �Ĺ��캯��"<<endl;
        this->name = new string(name);
    }
    void say(){
        cout<<"����ʵ�ָ�����鹹����"<<endl;
    }
    ~Cat(){
        if (name==NULL){
            delete name;
            name = NULL;
        }
        cout<<"�������������"<<endl;
    }
    string *name;
};

void test(){
    Animal *a = new Cat("Tom");
    a->say();
    //ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������
	//���������������������ͨ������ָ���ͷ��������
    delete a;
}
int main(){
    test();
}


