//
// Created by lenovo on 2021-06-16.
//
//3中值传递的方式
#include <iostream>
using namespace std;

void SwapValue_by_p(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
//地址传值
void SwapValue_by_loc(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

//引用传值
void SwapValue_by_y(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a = 10;
    int b = 20;
    cout <<"a的值:"<<a<<endl;
    cout <<"b的值:"<<b<<endl;

    SwapValue_by_p(a,b);

    cout <<"a的值:"<<a<<endl;
    cout <<"b的值:"<<b<<endl;
    SwapValue_by_loc(&a,&b);
    cout <<"a的值:"<<a<<endl;
    cout <<"b的值:"<<b<<endl;
    SwapValue_by_y(a,b);
    cout <<"a的值:"<<a<<endl;
    cout <<"b的值:"<<b<<endl;
}