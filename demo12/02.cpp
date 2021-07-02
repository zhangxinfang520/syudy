//@Time : 2021-06-29 11:49
//@Author: zxf_要努力
//@File : 02.h
//类模板分文件编写
#include "iostream"
using namespace std;

#include "Person.hpp"
//解决方式1：直接包含.cpp源文件

void test01(){
        Person<string,int> p("zxf",12);
        p.showPerson();
}



//第二种方式创建hpp文件将声明和实现写到一起，文件后缀名改为.hpp
void test02()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

int main(){
 //test01();
 test02();
}