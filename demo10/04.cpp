//@Time : 2021-06-24 11:56
//@Author: zxf_ҪŬ��
//@File : 04.h
// �����ƶ��ļ�
#include "iostream"
#include <fstream>
#include <string>
using namespace std;

class Person{
public:
    char m_Name[64];
    int age;
};

void test(){
    ifstream ifs;
    ifs.open("../demo10/person.txt", ios::in | ios::binary);

    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    Person p;
    ifs.read((char *) &p,sizeof(p));
	cout << "������ " << p.m_Name << " ���䣺 " << p.age << endl;
}

int main(){
    test();
}


