//@Time : 2021-06-28 14:41
//@Author: zxf_要努力
//@File : 06.h
// 类模板
// 作用：建立一个通用类，类中的成员 数据类型可以不具体制定， 用一个**虚拟的类型**来代表
//语法 template<typename T> 类
#include "iostream"
using namespace std;
#include "string"

template<class NameType,class AgeType=int>//可以有默认的类型
class Person{
public:
    Person(NameType name,AgeType age){
        this->name = name;
        this->age = age;
    }
    void showinfo(){
        cout << "名称为："<<this->name<<"年龄为："<<this->age<<endl;
    }
    NameType name;
    AgeType age;
};

void test(){
    //类模板 没有自动推导
    Person<string ,int> p("Zxf",23);
    p.showinfo();
}
int main(){
    test();
}