//@Time : 2021-06-19 16:58
//@Author: zxf_要努力
//@File : 03.h
//构造函数的构造方式
/*
 按参数分为： 有参构造和无参构造
 按类型分为： 普通构造和拷贝构造

 调用方式：
    括号法 显示法 隐式转换法

构造函数调用规则如下：
    * 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
    * 如果用户定义拷贝构造函数，c++不会再提供其他构造
拷贝函数的用法
    * 使用一个已经创建完毕的对象来初始化一个新对象
    * 值传递的方式给函数参数传值
    * 以值方式返回局部对象
 */
#include <iostream>
using namespace std;

class Person{
public:
     Person(){
        cout<<"无参构造函数"<<endl;
    }
     Person(int age){
        cout<<"有参构造函数"<<endl;
        age = age;
    }
    Person(const Person &p){
        age = p.age;
        cout<<"copy参构造函数"<<endl;
    }
    ~Person(){
         cout<<"析构造函数"<<endl;
    }
private:
    int age;
};
// 2构造函数的调用

void test(){
    //无参构造函数
    Person p;
}
//调用有参的构造函数
void test02(){
    //括号法
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p2();
	//显示法
	Person p2 = Person(10);
	Person p3 = Person(p2);
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	//2.3 隐式转换法
	Person p4 = 10; // Person p4 = Person(10);
	Person p5 = p4; // Person p5 = Person(p4);
	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person p5(p4);

}

int main(){
    test();
    test02();
};


