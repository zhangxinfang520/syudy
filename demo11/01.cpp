//@Time : 2021-06-28 11:30
//@Author: zxf_要努力
//@File : 01.h
//模板的slt的使用
//模板就是建立**通用的模具**，大大**提高复用性**
/*
 * 使用语法：template<typename T> 函数声明或定义
        template  ---  声明创建模板
        typename  --- 表面其后面的符号是一种数据类型，可以用class代替
        T    ---   通用的数据类型，名称可以替换，通常为大写字母
 * 作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表。
 * */

#include "iostream"

using namespace std;

void swapInt(int &a,int &b){
    int temp = a;
    a = b;
    b =temp;
}

void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}

//利用模板使用交换函数
template<typename T>
void swapT(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template<class T>
void func(){
    cout<<"func"<<endl;
}

void test(){
    //模板调用
    func<int>();
    int a = 10;
    int b = 20;
    swapInt(a,b);
    cout<<"a:" << a <<endl;
    cout<<"b:" << b <<endl;
    double c = 1.1;
    double d = 2.2;
    swapDouble(c,d);
    cout<<"c:" << c <<endl;
    cout<<"d:" << d <<endl;
    //模板调用方式
    //自动推导
    swapT(a,b);
    cout<<"a:" << a <<endl;
    cout<<"b:" << b <<endl;
    swapT(c,d);
    cout<<"c:" << c <<endl;
    cout<<"d:" << d <<endl;
    //显示指定
    swapT<int>(a,b);
    cout<<"a:" << a <<endl;
    cout<<"b:" << b <<endl;
    swapT<double>(c,d);
    cout<<"c:" << c <<endl;
    cout<<"d:" << d <<endl;

}
int main(){
    test();
}
