//@Time : 2021-06-20 16:19
//@Author: zxf_要努力
//@File : 05.h
//  成员变量和成员函数的存储位置
#include "iostream"
using namespace std;

class Person{
public:
    int age;//非静态成员变量占对象空间 int 占四个字节
    static int ip;//静态成员变量不占对象空间
    void func() {
		cout << "mA:" << this->age << endl;
	};//函数也不占对象空间，所有函数共享一个函数实例
    static void func1();//静态成员函数也不占对象空间
};

int main(){
    cout << sizeof(Person)<<endl;
    Person p;
    p.age = 10;
    p.func();
}

