//
// Created by lenovo on 2021-06-16.
//

#include <iostream>
using namespace std;
//ջ������ �ɱ���������Ϳ���
//�Ƿ�����
int *func(){
    int a = 10;//�ֲ����� �����ջ�� ջ���������ں���ִ������Զ��ͷ�
    return &a;//���ؾֲ�������ַ
}

//��Ҫ��ѧ����
int * func1(){
    //ָ�� ����Ҳ�Ǿֲ����� ����ջ�� ָ�뱣��������Ƿ��ڶ���
    int *p = new int(10);//�ŵ�����

    return p;
}

//�ڶ�����������
void func2(){
    //�����������ݵ����� �ڶ���
    int *arr = new int[10];
    for(int i=0;i<10;++i){
        arr[i] =  i + 10;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }
    //�ͷ�����
    delete[] arr;
}

int main(){
    func2();
    int *p = func();
    printf("%d\n",*p);
    printf("%d\n",*p);
    cout << *p <<endl;

    int *p1 = func1();
    printf("%d\n",*p1);
    printf("%d\n",*p1);
    //�����������ɳ���Ա����
    delete p1;
    printf("%d\n",*p1);

    return 0;
}