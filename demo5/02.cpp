//@Time : 2021-06-19 16:10
//@Author: zxf_要努力
//@File : 02.h
//构造函数和析构函数
#include <iostream>
using namespace std;

/*
 构造函数： 类名（）{}
    没有返回值 也不用void
    函数名称与类名相同
    构造函数可以有参数 可以发生重载
    程序在调用对象时候会自动调用构造函数 只会调用一次
 析构函数：~类名（）{} 用来释放的
    没有返回值 也不写void
    函数名称和类名相同 在名称前加上符号~
    析构函数不可以有参数 因此不可以发生重载
    程序在调用对象时候会自动调用构造函数 只会调用一次
 */

class  Person{
public:
    Person(){
        cout<<"构造函数调用"<<endl;
    };
    ~Person(){
        cout<<"析构函数调用"<<endl;
    }
};

void test(){
    Person p;
}
int main(){
    test();
    Person p;
    system("pause");
    return 0;
}



