//@Time : 2021-06-22 14:33
//@Author: zxf_要努力
//@File : 05.h
//多继承
#include "iostream"
using namespace std;

class Base{
public:
    Base(){
        a = 10;
    }
    int a;
};
class Base1{
public:
    Base1(){
        a = 20;
    }
    int a ;
};

class Son:public Base1,public Base{
public:
    Son(){
        b = 20;
        c = 30;
    }
    int b;
    int c;
};
void test(){
    Son s;
    cout<<s.Base::a;
    cout<<s.Base1::a;
    cout<<s.b;
    cout<<s.c;
}
int main(){
    test();
}



