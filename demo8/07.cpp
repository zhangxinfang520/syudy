//@Time : 2021-06-22 15:20
//@Author: zxf_要努力
//@File : 07.h
//动态多态
#include "iostream"
using namespace std;

class Animal{
public:
    //函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
    virtual void see(){
        cout<<"Animal"<<endl;
    }
};

class Dog:public Animal{
public:
    void see(){
       cout<<"Dog"<<endl;
    }
};
class Cat:public Animal{
public:
    void see(){
       cout<<"Cat"<<endl;
    }
};

//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编

void dosee(Animal &animal){
    animal.see();
}
//
//多态满足条件：
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

void test(){
    Cat cat;
    dosee(cat);
    Dog dog;
    dosee(dog);
}

int main(){
    test();
}
