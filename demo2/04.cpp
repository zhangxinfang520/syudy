//
// Created by lenovo on 2021-06-16.
//
//3��ֵ���ݵķ�ʽ
#include <iostream>
using namespace std;

void SwapValue_by_p(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
//��ַ��ֵ
void SwapValue_by_loc(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

//���ô�ֵ
void SwapValue_by_y(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a = 10;
    int b = 20;
    cout <<"a��ֵ:"<<a<<endl;
    cout <<"b��ֵ:"<<b<<endl;

    SwapValue_by_p(a,b);

    cout <<"a��ֵ:"<<a<<endl;
    cout <<"b��ֵ:"<<b<<endl;
    SwapValue_by_loc(&a,&b);
    cout <<"a��ֵ:"<<a<<endl;
    cout <<"b��ֵ:"<<b<<endl;
    SwapValue_by_y(a,b);
    cout <<"a��ֵ:"<<a<<endl;
    cout <<"b��ֵ:"<<b<<endl;
}