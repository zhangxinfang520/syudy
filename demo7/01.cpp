//@Time : 2021-06-21 11:05
//@Author: zxf_ҪŬ��
//@File : 01.h
// ��Ԫ ѧϰ
#include "iostream"
#include <string>
using namespace std;

class Building{
    //���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
    friend void goodGay(Building *b);

public:
    Building(){
        m_public_room = "��������";
        m_private_room = "˽������";
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

