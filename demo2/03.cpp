//
// Created by lenovo on 2021-06-16.
//
#include <iostream>
using namespace std;



int main(){
    //引用基本语法
    //数据类型 &别名 = 原名
    int a=10;
    //引用必须要初始化 一旦初始化后 不能更改
    int &b = a;//这里为赋值
    int c = 30;

    b = c;//这里为赋值
    cout<<b<<endl;


    cout<<a<<endl;
    system("pause");
}
