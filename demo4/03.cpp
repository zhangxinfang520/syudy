//@Time : 2021-06-18 20:07
//@Author: zxf_要努力
//@File : 03.h
// struct 和class 区别
#include <iostream>
using namespace std;

class  C{
    int m_A;//默认权限为private
};

struct C2{
    int m_A;
};
int main(){
    //struct 和 class 区别
    // struct 默认权限是公共的public
    // class 默认权限是私有 private
    C c1;
    //c1.m_A = 10;这个报错
    C2 c2;
    c2.m_A = 10;
}


