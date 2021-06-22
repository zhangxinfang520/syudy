//@Time : 2021-06-22 13:51
//@Author: zxf_要努力
//@File : 03.h
//
#include "iostream"
using namespace std;
class Base{
public:
    Base(){
    cout<<" base 构造函数"<<endl;
    }
    ~Base(){
    cout<<"base 析构函数"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
    cout<<"son 构造函数"<<endl;
    }
    ~Son(){
    cout<<"son 析构函数"<<endl;
    }
};

void test(){
    Son();
}


int main(){
    test();
}
