//
// Created by lenovo on 2021-06-16.
//
#include <iostream>
using namespace std;

//�����ǿ�����Ϊ�����ķ���ֵ���ڵ�

//���ؾֲ�����
int& test01(){
    int a = 10;//�ֲ�����
    return a;
}
//���ؾ�̬��������
int& test02(){
    static int a = 20;//��̬���� �����ȫ���� ȫ�����ϵ������ڳ���������ͷ�
    return a;
};


int main(){
    //���û����﷨
    //�������� &���� = ԭ��
    int a=10;
    //���ñ���Ҫ��ʼ�� һ����ʼ���� ���ܸ���
    int &b = a;//����Ϊ��ֵ
    int c = 30;

    int &ref = test01();
    cout<<ref<<endl;//��һ����ȷ ���������˱���
    cout<<ref<<endl;//�ڶ��� ������� a���ڴ��Ѿ��ͷ�

    int &ref01 = test02();
    cout<<ref01<<endl;//��һ����ȷ ���������˱���
    cout<<ref01<<endl;//�ڶ��� ������� a���ڴ��Ѿ��ͷ�

    //�����ķ��ؿ�����Ϊ ��ֵ
    test02() = 1000;
    cout<<ref01<<endl;//�����ref01�Ǳ���

    b = c;//����Ϊ��ֵ
    cout<<b<<endl;
    cout<<a<<endl;
    system("pause");
}
