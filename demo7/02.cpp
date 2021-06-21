//@Time : 2021-06-21 11:21
//@Author: zxf_要努力
//@File : 02.h
//类 做友元 同时将类的成员函数在内外实现
#include "iostream"
#include <string>
using namespace std;

class Building;

class goodGay{
public:
    goodGay();
    void visit();

private:
    Building *b;
};

class Building{
    friend goodGay;
public:
    Building();
    string m_public_room;
private:
    string m_private_room;
};

//成员函数在内外实现
Building::Building(){
    m_public_room = "公共区域";
    m_private_room = "私密区域";
}

goodGay::goodGay(){
    b = new Building;
}
void goodGay::visit(){
    cout<< b->m_public_room<<endl;
    cout<< b->m_private_room<<endl;
}

void test(){
    goodGay gd;
    gd.visit();
}


int main(){
    test();
}

