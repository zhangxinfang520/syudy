//@Time : 2021-06-21 11:38
//@Author: zxf_ҪŬ��
//@File : 03.h
// ��Ա��������Ԫ
#include "iostream"
#include <string>
using namespace std;

class Building;
class goodGay{

public:
    goodGay();
    void visit();//ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
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
    m_public_room = "��������";
    m_private_room = "˽������";
}

goodGay::goodGay() {
    b = new Building;
}
void goodGay::visit(){
    cout<<"visit1 ���ڷ���:"<< b->m_public_room<<endl;
    cout<<"visit1 ���ڷ���:"<< b->m_private_room<<endl;
}
void goodGay::visit1(){
     cout<<"visit2 ���ڷ���:"<< b->m_public_room<<endl;
     //cout<<"visit ���ڷ���:"<< b->m_private_room<<endl;
}

void test(){
    goodGay g;
    g.visit();
    g.visit1();
}
int main(){
    test();
}