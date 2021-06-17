//@Time : 2021-06-17 10:37
//@Author: zxf_要努力
//@File : 02.h
//函数重载 函数名相同 提高复用性

/*满足条件
 1.同一个作用域下
 2.函数名称相同
 3.函数的参数类型不同或者个数不同或者顺序不同
 */
#include <iostream>
using namespace std;

void func(){
    cout<<"这里没有参数的调用"<<endl;
}

void func(int a){
    cout<<"这里有一个int参数的调用"<< a <<endl;
}

void func(double a){
    cout<<"这里有一个double参数的调用"<< a <<endl;
}
void func(int a,double b){
    cout<<"这里有一a,b参数的调用"<< a<<b <<endl;
}

void func(double b,int a){
    cout<<"这里有一b,a参数的调用"<< a<<b <<endl;
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


