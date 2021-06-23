//@Time : 2021-06-23 15:56
//@Author: zxf_要努力
//@File : 01.h

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
//因此可以将虚函数改为纯虚函数
//纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0
/*
抽象类特点：
 * 无法实例化对象
 * 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/

#include "iostream"

using namespace std;

class Base{
public:
    //纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void fun()=0;
};

class Son:public Base{
public:
    virtual void fun(){
        cout<<"子类必须实现父类的虚函数"<<endl;
    }
};

void test(){
    Son s;
    s.fun();
}
int main(){
    test();
    return 0;
}
