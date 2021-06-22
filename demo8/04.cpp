//@Time : 2021-06-22 14:04
//@Author: zxf_要努力
//@File : 04.h
// 子类和父类的同名函数
#include "iostream"
using namespace std;

class Base{
public:
    Base(){
        a = 10;
    }
    void func(){
        cout<<"我是base的 fun"<<endl;
    }

    static void func1(){
        cout<<"我是静态方法"<<endl;
    }
    //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func(int a){
        cout<<"我是base的带参数的 fun"<<endl;
    }
    int a;
};

class Son:public Base{
public:
    Son(){
        a = 20;
    }
    void func(){
        cout<<"Son的func"<<endl;
    }
    int a;
};

void test(){
    Son s;
    //子类和父类属性同名的时候 访问的是子类的属性
    cout<<s.a<<endl;
    //如果想访问 父类 需要添加作用域
    cout<<s.Base::a<<endl;

    //访问函数时：
    s.func();
    //静态方法的访问方式
    s.func1();
    Son::Base::func1();
    //s.func(10); 相访问Base的带参数的函数 访问不了 因为已经被父类覆盖
    s.Base::func(10);
    s.Base::func();

}

int main(){
    test();
}
