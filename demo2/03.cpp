//
// Created by lenovo on 2021-06-16.
//
#include <iostream>
using namespace std;



int main(){
    //���û����﷨
    //�������� &���� = ԭ��
    int a=10;
    //���ñ���Ҫ��ʼ�� һ����ʼ���� ���ܸ���
    int &b = a;//����Ϊ��ֵ
    int c = 30;

    b = c;//����Ϊ��ֵ
    cout<<b<<endl;


    cout<<a<<endl;
    system("pause");
}
