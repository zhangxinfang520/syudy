//@Time : 2021-06-24 11:56
//@Author: zxf_要努力
//@File : 04.h
// 二进制读文件
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
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *) &p,sizeof(p));
	cout << "姓名： " << p.m_Name << " 年龄： " << p.age << endl;
}

int main(){
    test();
}


