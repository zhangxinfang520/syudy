//@Time : 2021-06-28 14:41
//@Author: zxf_ҪŬ��
//@File : 06.h
// ��ģ��
// ���ã�����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ��� ��һ��**���������**������
//�﷨ template<typename T> ��
#include "iostream"
using namespace std;
#include "string"

template<class NameType,class AgeType=int>//������Ĭ�ϵ�����
class Person{
public:
    Person(NameType name,AgeType age){
        this->name = name;
        this->age = age;
    }
    void showinfo(){
        cout << "����Ϊ��"<<this->name<<"����Ϊ��"<<this->age<<endl;
    }
    NameType name;
    AgeType age;
};

void test(){
    //��ģ�� û���Զ��Ƶ�
    Person<string ,int> p("Zxf",23);
    p.showinfo();
}
int main(){
    test();
}