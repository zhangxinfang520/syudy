//@Time : 2021-06-20 12:02
//@Author: zxf_要努力
//@File : 01.h
// 深浅拷贝的学习

/*
 浅拷贝：简单的赋值操作 带来的问题 就是堆区的内存重复释放
 深拷贝：在堆区重新申请空间 进行拷贝操作
 */
#include <iostream>
using namespace std;

//class Person{
//public:
//    Person(){
//        cout<<"Person 的默认构造函数"<<endl;
//    }
//    Person(int age,int height){
//        a_Age = age;
//        a_Height  = height;
//        cout<<"Person 的有参数的构造函数"<<endl;
//    }
//    ~Person(){
//        cout<<"析构函数调用"<<endl;
//    }
//
//    int a_Age;
//    int a_Height;
//};

class Person{
public:
    Person(){
        cout<<"Person 的默认构造函数"<<endl;
    }
    Person(int age,int height){
        a_Age = age;
        a_Height  = new int(height);
        cout<<"Person 的有参数的构造函数"<<endl;
    }
    Person(const Person &p){
        a_Age = p.a_Age;
        //a_Height = p.a_Height; 这个是编译器的操作
        //进行深拷贝 重新申请一块堆区内存存放变量
        a_Height = new int(*p.a_Height);

    }
    ~Person(){
        //析构函数 将堆区开辟的数据做释放操作
        if(a_Height !=NULL){
            delete a_Height;
            a_Height == NULL;
        }
        cout<<"析构函数调用"<<endl;
    }

    int a_Age;
    int* a_Height;
};

void test01(){
    Person p1(18,160);
    cout << "p1的年龄： " << p1.a_Age << " 身高： " << *p1.a_Height << endl;
    Person p2(p1);
    cout << "p1的年龄： " << p1.a_Age << " 身高： " << *p1.a_Height << endl;
}
int main(){
    test01();
}
