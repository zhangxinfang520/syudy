//@Time : 2021-06-22 14:04
//@Author: zxf_ҪŬ��
//@File : 04.h
// ����͸����ͬ������
#include "iostream"
using namespace std;

class Base{
public:
    Base(){
        a = 10;
    }
    void func(){
        cout<<"����base�� fun"<<endl;
    }

    static void func1(){
        cout<<"���Ǿ�̬����"<<endl;
    }
    //�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
    void func(int a){
        cout<<"����base�Ĵ������� fun"<<endl;
    }
    int a;
};

class Son:public Base{
public:
    Son(){
        a = 20;
    }
    void func(){
        cout<<"Son��func"<<endl;
    }
    int a;
};

void test(){
    Son s;
    //����͸�������ͬ����ʱ�� ���ʵ������������
    cout<<s.a<<endl;
    //�������� ���� ��Ҫ���������
    cout<<s.Base::a<<endl;

    //���ʺ���ʱ��
    s.func();
    //��̬�����ķ��ʷ�ʽ
    s.func1();
    Son::Base::func1();
    //s.func(10); �����Base�Ĵ������ĺ��� ���ʲ��� ��Ϊ�Ѿ������า��
    s.Base::func(10);
    s.Base::func();

}

int main(){
    test();
}
