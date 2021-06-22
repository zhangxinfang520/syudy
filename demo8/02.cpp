//@Time : 2021-06-22 10:49
//@Author: zxf_要努力
//@File : 02.h
//继承中的方式 public protected private
//类属性的变化
#include "iostream"
using namespace std;

class Base{
public:
    int a;
protected:
    int b;
private:
    int c;
};
//public 方式继承
class Son1:public Base{
public:
    void func(){
        a = 10;
        b = 20;
        //c = 20; 为私有属性 无法访问
    }
};

int test01(){
    Son1 s;
    s.a = 1000;
    //s.b = 20;受保护的属性 使用public继承后还是受保护的 内外无法访问
}

class Son2:protected Base{
public:
    void func(){
        a = 10;
        b = 20;
        //c = 30;私有变量无法访问
    }
};

void test02(){
    Son2 s2;
    //s2.a; protected 方式继承 除了private 以外的所有属性都转化为了protected属性
}

class Son3:private Base{

public:
    void fuc() {
        a = 10;
        b = 20;
        //c = 10; 私有变量 任何方式都不可以继承
    }
};

void test03(){
    Son3 s3;
    //s3.a;所有属性都无法访问

}

int main(){

}

