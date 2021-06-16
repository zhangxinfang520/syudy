//
// Created by lenovo on 2021-06-16.
//
//全局变量
#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a= 10;
const int c_g_b= 10;

int main(){
    //局部变量
    int a = 10;
    int b = 10;
    //打印地址
    cout << "局部变量a地址为" << &a <<endl;
    cout << "局部变量b地址为" << &b <<endl;
    cout << "******************" <<endl;

    cout << "全局局部变量g_a地址为" << &g_a <<endl;
    cout << "全局局部变量g_b地址为" << &g_b <<endl;
    cout << "******************" <<endl;
    cout << "全局局部常量c_g_a地址为" << &c_g_a <<endl;
    cout << "全局局部常量c_g_b地址为" << &c_g_b <<endl;

    //局部常量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "******************" <<endl;
    cout << "局部常量c_g_a地址为" << &c_l_a <<endl;
    cout << "局部常量c_g_b地址为" << &c_l_b <<endl;
    system("pause");
    return 0;
}
