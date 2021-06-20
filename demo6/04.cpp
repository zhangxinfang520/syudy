//@Time : 2021-06-20 15:33
//@Author: zxf_要努力
//@File : 04.h
//静态成员变量和静态成员函数
/*
 静态成员就是在成员变量和成员函数前加上关键字static

 静态成员分为：
    静态成员变量 ：所有对象共享同一份数据 在编译阶段分配内存 类内声明，类外初始化
    静态成员函数 : 所有对象共享同一个函数 静态成员函数只能访问静态成员变量
 */
#include "iostream"
using namespace std;

class Person{
public:
    static int m_A;
    static void func(){
        cout <<"func调用"<<endl;
        m_A = 100;
        m_B = 10;
        //m_C = 100; 访问不到 非静态变量

    }
    int m_C;
private:
    static int m_B;
    static void func2()
	{
		cout << "func2调用" << endl;
	}
};

int Person::m_A=10;
int Person::m_B=10;
void test01(){
    //静态变量的访问方式
    //1 通过对象
    Person p1;
    p1.m_A = 10;
    cout << "p1.m_A="<<p1.m_A<<endl;

    Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;

	//2通过类名
	cout<<"类名访问"<<Person::m_A<<endl;
	//cout<<"类名访问"<<Person::m_B<<endl; 私有权限访问不到
}

void test02(){
    Person p1;
    p1.func();
    //p1.func2();

    Person::func();
    //Person::func2() 访问不到
}
int main(){
    test02();
    return 0;
}
