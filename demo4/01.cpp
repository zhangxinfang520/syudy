//@Time : 2021-06-17 11:35
//@Author: zxf_要努力
//@File : 01.h
// 类学习
#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle{
    public:
    int m_r;
    double calculateZC(){
        return 2*PI*m_r;
    }
};

int main(){
    Circle cir ;
    cir.m_r = 15;
    cout << cir.calculateZC()<<endl;
}

