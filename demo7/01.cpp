//@Time : 2021-06-21 11:05
//@Author: zxf_要努力
//@File : 01.h
// 友元 学习
#include "iostream"
#include <string>
using namespace std;

class Building{
    //告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGay(Building *b);

public:
    Building(){
        m_public_room = "公共区域";
        m_private_room = "私密区域";
    }
    string m_public_room;
private:
    string m_private_room;
};

void goodGay(Building *b){
    cout << b->m_public_room<<endl;
    cout << b->m_private_room<<endl;
}
void test01(){
    Building b;
    goodGay(&b);
}

int main(){
    test01();
}

