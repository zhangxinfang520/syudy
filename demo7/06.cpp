//@Time : 2021-06-21 14:13
//@Author: zxf_要努力
//@File : 06.h
//递增和递减的重载实现
#include "iostream"
using namespace std;

class MyInter{
    friend ostream &operator<<(ostream &cout,MyInter my);
public:
    MyInter(){
        m_Num = 0;
    }
    //前置++ 这里返回的引用
    MyInter &operator++(){
        //先加 在进行返回
        m_Num ++;
        return *this;
    }
    MyInter &operator--(){
        m_Num --;
        return *this;
    }
    //后置++ 这里返回的是值
    MyInter operator++(int){
        //先记录原来的值
        MyInter temp = *this;//记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        m_Num ++;
        //先返回 然后在加值
        return temp;
    }

    MyInter operator--(int){
        MyInter temp = *this;
        m_Num--;
        return temp;
    }
private:
    int m_Num;
};

ostream &operator<<(ostream &cout,MyInter my){
    cout << my.m_Num <<endl;
    return cout;
}

void test(){
    MyInter inter;
    cout << inter;
    cout << inter++;
    cout << inter;
    cout << ++inter;
    cout << inter--;
    cout << inter;
    cout << --inter;
    cout << inter;
}
int main(){
    test();
}

