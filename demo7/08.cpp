//@Time : 2021-06-21 14:59
//@Author: zxf_要努力
//@File : 08.h
//重载 ==运算符
#include "iostream"
using namespace std;

class Person{
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }

    bool operator==(Person &p){
        if ((name == p.name)&&(age==p.age)){
            return true;
        } else{
            return false;
        }
    }
    string  name;
    int age;
};

void test(){
    Person p1("zxf",18);
    Person p2("zxf",19);
    if(p1==p2){
        cout<<"两者相等"<<endl;
    }else{
        cout<<"两者不相等"<<endl;
    }
}
int main(){
    test();
}

