//@Time : 2021-06-17 10:37
//@Author: zxf_ҪŬ��
//@File : 02.h
//�������� ��������ͬ ��߸�����

/*��������
 1.ͬһ����������
 2.����������ͬ
 3.�����Ĳ������Ͳ�ͬ���߸�����ͬ����˳��ͬ
 */
#include <iostream>
using namespace std;

void func(){
    cout<<"����û�в����ĵ���"<<endl;
}

void func(int a){
    cout<<"������һ��int�����ĵ���"<< a <<endl;
}

void func(double a){
    cout<<"������һ��double�����ĵ���"<< a <<endl;
}
void func(int a,double b){
    cout<<"������һa,b�����ĵ���"<< a<<b <<endl;
}

void func(double b,int a){
    cout<<"������һb,a�����ĵ���"<< a<<b <<endl;
}

int main(){
    int a = 10;
    double b = 20;
    func();
    func(a);
    func(b);
    func(a,b);
    func(b,a);

}


