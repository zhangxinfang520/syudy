//@Time : 2021-06-29 14:10
//@Author: zxf_要努力
//@File : main.h
//类模板案例
/*
 *案例描述:  实现一个通用的数组类，要求如下：
    * 可以对内置数据类型以及自定义数据类型的数据进行存储
    * 将数组中的数据存储到堆区
    * 构造函数中可以传入数组的容量
    * 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
    * 提供尾插法和尾删法对数组中的数据进行增加和删除
    * 可以通过下标的方式访问数组中的元素
    * 可以获取数组中当前元素个数和数组的容量
*/
#include "iostream"
using namespace std;
#include "myArray.hpp"
#include <string>

void PrintArray(MyArray<int> &arr){
    for (int i = 0; i <arr.getSize(); ++i) {
        cout << arr[i]<<endl;
    }
}

void test(){
    MyArray<int> p(5);
    for (int i = 0; i <5 ; ++i) {
        p.Push_back(i);
    }
    PrintArray(p);

    cout<<"数组容量："<<p.getCapacity()<<endl;
    cout<<"数组size："<<p.getSize()<<endl;
    MyArray<int> p1(p);
    cout<<"删除后的大小"<<endl;
    p1.Pop_back();
     cout<<"数组容量："<<p1.getCapacity()<<endl;
    cout<<"数组size："<<p1.getSize()<<endl;
    PrintArray(p1);
}

class Person{
public:
    Person(){};
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};


void PrintArray1(MyArray<Person> &arr){
    for (int i = 0; i <arr.getSize(); ++i) {
        cout << arr[i].name<<" ";
        cout << arr[i].age<<" ";
        cout<<endl;
    }
}

void test01(){
    //测试自定义对象的使用
    Person p("zxf01",18);
    Person p2("zxf01",19);
    Person p3("zxf01",20);
    Person p4("zxf01",21);
    Person p5("zxf01",22);
    MyArray<Person> arr01(10);
    arr01.Push_back(p);
    arr01.Push_back(p2);
    arr01.Push_back(p3);
    arr01.Push_back(p4);
    arr01.Push_back(p5);
    PrintArray1(arr01);

}
int main(){
    //test();
   test01();
   system("pause");
}

