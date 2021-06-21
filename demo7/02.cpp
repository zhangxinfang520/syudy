//@Time : 2021-06-21 11:21
//@Author: zxf_ҪŬ��
//@File : 02.h
//�� ����Ԫ ͬʱ����ĳ�Ա����������ʵ��
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

//��Ա����������ʵ��
Building::Building(){
    m_public_room = "��������";
    m_private_room = "˽������";
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

