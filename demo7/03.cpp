//@Time : 2021-06-21 11:38
//@Author: zxf_要努力
//@File : 03.h
// 成员函数做友元
#include "iostream"
#include <string>
using namespace std;

class Building;
class goodGay{

public:
    goodGay();
    void visit();//只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit1();
private:
    Building *b;
};

class Building{
    friend void goodGay::visit();
public:
    Building();
    string m_public_room;
private:
    string m_private_room;
};

Building::Building(){
    m_public_room = "公共区域";
    m_private_room = "私密区域";
}

goodGay::goodGay() {
    b = new Building;
}
void goodGay::visit(){
    cout<<"visit1 正在访问:"<< b->m_public_room<<endl;
    cout<<"visit1 正在访问:"<< b->m_private_room<<endl;
}
void goodGay::visit1(){
     cout<<"visit2 正在访问:"<< b->m_public_room<<endl;
     //cout<<"visit 正在访问:"<< b->m_private_room<<endl;
}

void test(){
    goodGay g;
    g.visit();
    g.visit1();
}
int main(){
    test();
}