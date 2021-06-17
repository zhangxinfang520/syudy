//
// Created by lenovo on 2021-06-16.
//
#include <iostream>
using namespace std;

//引用是可以作为函数的返回值存在的

//返回局部变量
int& test01(){
    int a = 10;//局部变量
    return a;
}
//返回静态变量引用
int& test02(){
    static int a = 20;//静态变量 存放在全局区 全局区上的数据在程序结束后释放
    return a;
};


int main(){
    //引用基本语法
    //数据类型 &别名 = 原名
    int a=10;
    //引用必须要初始化 一旦初始化后 不能更改
    int &b = a;//这里为赋值
    int c = 30;

    int &ref = test01();
    cout<<ref<<endl;//第一次正确 编译器做了保留
    cout<<ref<<endl;//第二次 结果错误 a的内存已经释放

    int &ref01 = test02();
    cout<<ref01<<endl;//第一次正确 编译器做了保留
    cout<<ref01<<endl;//第二次 结果错误 a的内存已经释放

    //函数的返回可以作为 左值
    test02() = 1000;
    cout<<ref01<<endl;//这里的ref01是别名

    b = c;//这里为赋值
    cout<<b<<endl;
    cout<<a<<endl;
    system("pause");
}
