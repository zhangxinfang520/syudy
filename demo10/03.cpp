//@Time : 2021-06-24 11:44
//@Author: zxf_要努力
//@File : 03.h
// 二进制写文件
#include "iostream"
using namespace std;
#include <fstream>

class Person{
public:
    char m_Name[64];
    int age;
};

void test(){
    ofstream ofs;
    ofs.open("../demo10/person.txt",ios::trunc |ios::binary);

    Person p ={"张鑫方",18};

    ofs.write((const char*) &p,sizeof(p));

    ofs.close();

}
int main(){
    test();
}